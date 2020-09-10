class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};


class Solution {
private:
    vector<vector<int> > ret;
    vector<int> temp;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, int pre_sum, int cur){
        if(cur == candidates.size())
            return;
        

        //等于target，满足条件时
        if(pre_sum == target){
            ret.push_back(temp);
            return;
        }
        //选当前值
        if(candidates[cur]+pre_sum <= target){
            
            temp.push_back(candidates[cur]);
            dfs(candidates, target, pre_sum+candidates[cur], cur);
            temp.pop_back();
            
        }
        //不选当前值
        dfs(candidates, target, pre_sum, cur+1);     
    }
};