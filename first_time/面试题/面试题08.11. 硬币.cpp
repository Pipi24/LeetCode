class Solution {
public:
    int waysToChange(int n) {
        //dp[i][j]表示前i个硬币组成金额j的方法数
        vector<vector<int>> dp(4,vector<int>(n+1,0));
        int coins[4] = {1,5,10,25};

        for(int i=0; i<4; ++i)
            dp[i][0] = 1;
        //前0个硬币（1分）的方法数
		//下面有dp[i-1][j]，因此i要从1开始，所以这里初始化i=0
        for(int i=0; i<=n; ++i)
            dp[0][i] = 1;

        for(int i=1; i<4; i++){
            for(int j=1; j<=n; ++j){
                if(j>=coins[i])
                    dp[i][j] = (dp[i-1][j]+dp[i][j-coins[i]])%1000000007;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[3][n];
    }
};

class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n+1,0);
        int coins[4] = {1,5,10,25};
        //用第一个硬币
        for(int i=0; i<=n; ++i)
            dp[i] = 1;
        //用后面的硬币
        for(int i=1; i<4; i++){
            for(int j=coins[i]; j<=n; ++j){
                dp[j] = (dp[j]+dp[j-coins[i]])%1000000007;
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n+1,0);
        int coins[4] = {1,5,10,25};

        //n为0时，1种解法
        dp[0] = 1;

        for(int i=0; i<4; i++){
            for(int j=coins[i]; j<=n; ++j){
                dp[j] = (dp[j]+dp[j-coins[i]])%1000000007;
            }
        }
        return dp[n];
    }
};