class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int len = nums.size();
        vector<int> del_first(len+1,0),del_last(len+1,0);
        for(int i = 2; i < len+1; ++i){
            del_first[i] = max(del_first[i-1], del_first[i-2] + nums[i-1]);
            del_last[i] = max(del_last[i-1], del_last[i-2] + nums[i-2]);
        }
        return max(del_first[len], del_last[len]);
    }
};