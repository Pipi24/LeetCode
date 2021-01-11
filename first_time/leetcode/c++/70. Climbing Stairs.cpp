class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        int dp_2 = 1;
        int dp_1 = 1;
        int dp = 1;
        for(int i=2; i<=n; i++){
            dp = dp_1 +dp_2;
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp;
    }
};