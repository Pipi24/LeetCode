class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int> >dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[prices.size()-1][1], dp[prices.size()-1][2]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int dp1 = -prices[0];
        int dp2 = 0;
        int dp3 = 0;
        for(int i = 1; i < prices.size(); ++i){
            int tmp1 = max(dp1, dp3 - prices[i]);
            int tmp2 = dp1 + prices[i];
            int tmp3 = max(dp2, dp3);
            dp1 = tmp1;
            dp2 = tmp2;
            dp3 = tmp3;
        }
        return max(dp2, dp3);
    }
};