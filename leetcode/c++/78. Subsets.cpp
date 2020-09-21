class Solution {
private:
    vector<vector<int> >ans;
    vector<int> tmp;

    void dfs(vector<int>& nums, int pos){
        if(pos==nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[pos]);
        dfs(nums, pos+1);
        tmp.pop_back();
        dfs(nums, pos+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};