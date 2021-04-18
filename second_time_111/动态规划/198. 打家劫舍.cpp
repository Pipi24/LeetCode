class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(2, 0);
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i){
            int curSum = max(dp[0] + nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = curSum;
        };
        return dp[1];
    }
};