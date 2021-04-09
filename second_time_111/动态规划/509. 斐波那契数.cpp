class Solution {
public:
    int fib(int n) {
        vector<int> dp(2,0);
        dp[0] = 0;
        dp[1] = 1;
        if(n < 2)
            return dp[n];
        for(int i=2; i<=n; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};