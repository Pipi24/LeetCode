class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int result1 = robHelper(nums, 0, nums.size() - 2);
        int result2 = robHelper(nums, 1, nums.size() - 1);
        return max(result1, result2);
    }
    int robHelper(vector<int>& nums, int s, int e){
        vector<int> dp(2, 0);
        dp[0] = nums[s];
        dp[1] = max(nums[s], nums[s + 1]);
        for(int i = s + 2; i <= e; ++i){
            int curSum = max(dp[0] + nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = curSum;
        }
        return dp[1];
    }
};