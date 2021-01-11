class Solution {
private:
    vector<vector<int> > ans;
    vector<int> tmp;
public:
    void dfs(vector<int>& nums, int pos, vector<int>& vit ){
        if(pos == nums.size()){
            ans.push_back(tmp);
            return ;
        }

        for(int i=0; i<nums.size(); ++i){
            if(vit[i])
                continue;
            vit[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, pos+1, vit);
            vit[i] = 0;
            tmp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vit(nums.size(), 0);
        dfs(nums,0,vit);
        return ans;
    }
};