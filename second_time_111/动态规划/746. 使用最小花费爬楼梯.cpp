class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp0 = cost[0];
        int dp1 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int dpi = min(dp0, dp1) + cost[i];
            dp0 = dp1; // 记录一下前两位
            dp1 = dpi;
        }
        return min(dp0, dp1);
    }
};