class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0;
        int sum = 0;
        for(int j=0; j < nums.size(); ++j){
            sum += nums[j];
            while(sum>=target){
                int l = j-i+1;
                ans = ans > l? l: ans;
                sum -= nums[i++];
            }
        }
        return ans==INT_MAX? 0: ans;
    }
};