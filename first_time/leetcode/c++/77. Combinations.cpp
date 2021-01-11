/* DFS+回溯
时间复杂度为 O((k^ n_)) 的组合枚举，由于每次记录答案的复杂度为 O(k)，故这里的时间复杂度为 O((k^ n_)*k)
空间复杂度：O(n+k)=O(n)，即递归使用栈空间的空间代价和临时数组 temp 的空间代价。 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> now_combine;
        dfs(1, n, k, ret, now_combine);
        return ret;
    }
    void dfs(int s, int e, int k, vector<vector<int> >& ret, vector<int>& now){
        //k个数了，加到结果中
        if(now.size()==k){
            ret.push_back(now);
            return;
        }
        if(s>e)
            return;

        //选当前这个数
        now.push_back(s);
        //递归后面的
        //if(s<e)
        dfs(s+1, e, k, ret, now);
        //不选当前这个数
        now.pop_back();
        //递归后面的
        //if(s<e)
        dfs(s+1, e, k, ret, now);
    }
};

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

