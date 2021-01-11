/*
重复产生的原因是数组存在重复数字，所以将重复数字放在一起递归，具体的:
1）首先把给candidates排序，让其相同的元素都挨在一起。 
2）使用hash统计每个数字的次数
3）分别调用选择 0, 1,⋯,most 次 x 的递归函数, 在递归之前需要同时满足不超过该数字的次数，以及和不大于target
4）递归时应跳到下一个不同数字的位置上

一个优化方法（提前回溯）是：将数组排序后，当当前数加上pre_sum大于target时，后面的数加上pre_sum也必然大于target，因此提前回溯
*/
class Solution {
private:
    unordered_map<int, int> map;
    vector<vector<int> > ret;
    vector<int> temp;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        //统计次数
        for(int i=0; i<candidates.size(); ++i){
            if(map.find(candidates[i]) == map.end())
                map[candidates[i]] = 1;
            else
                map[candidates[i]] ++;
        }
        dfs(candidates, target, 0, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, int pre_sum, int cur){
        //等于target，满足条件时
        if(pre_sum == target){
            ret.push_back(temp);
            return;
        }

        if(cur == candidates.size() || pre_sum+candidates[cur]>target)
            return;

        //不选当前值，跳到下一个不同数字的位置上
        dfs(candidates, target, pre_sum, cur+map[candidates[cur]]);   

        //选当前值，先确定当前值可选次数的最大值
        int most = min((target-pre_sum)/candidates[cur], map[candidates[cur]]);
        for(int i=1; i<=most; ++i){
            temp.push_back(candidates[cur]);
            dfs(candidates, target, pre_sum + i*candidates[cur], cur+map[candidates[cur]]);

        }
        for(int i=1; i<=most; ++i){
            temp.pop_back();
        }
    }
};

/* 在上面方法的基础上，使用vector<pair<int, int>> freq作为hash，注意下面方法的pos是在freq数组的位置，pos+1是candidates中下一个不同的元素，而不是candidates中的下一个元素

时间复杂度：O(2^n * n)，其中 n 是数组 candidates 的长度。在大部分递归 + 回溯的题目中，我们无法给出一个严格的渐进紧界，故这里只分析一个较为宽松的渐进上界。
在最坏的情况下，数组中的每个数都不相同，那么列表 freq 的长度同样为 n。在递归时，每个位置可以选或不选，如果数组中所有数的和不超过 target，那么 2^n 种组合都会被枚举到；
在 target 小于数组中所有数的和时，我们并不能解析地算出满足题目要求的组合的数量，但我们知道每得到一个满足要求的组合，需要 O(n) 的时间将其放入答案中，因此可估算出一个宽松的时间复杂度上界。
- 由于 O(2^n * n) 在渐进意义下大于排序的时间复杂度 O(nlogn)，因此后者可以忽略不计。

空间复杂度：O(n)。除了存储答案的数组外，我们需要 O(n) 的空间存储列表 freq、递归中存储当前选择的数的列表、以及递归需要的栈。 */

class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        //到下一个不同的数
        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};
