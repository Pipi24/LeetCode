class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> ans(5*n+1,0);
        if(n==0)
            return ans;
        vector<double> dp(6*n+1,0);
        
        double all  = pow(6, n);
        for(int i=1; i<=6; ++i){
            dp[i]=1;
            ans[i-1]=1.0/6;
        }
        for(int i=2; i<=n; ++i){//每一个骰子
            for(int j=6*n; j>=1; j--){//n个骰子的点数范围[n,6n],从后前向遍历，避免覆盖，减少一维
                int temp = 0;
                for(int k=1; k<=6; ++k){//多一个骰子，来源点数有6中，递推公式
                    temp += (j>=k)?dp[j-k]:0;
                }
                dp[j] = temp;
                if(i==n&&j>=n){
                    ans[j-i] = dp[j]/all;
                }
            }
        }
        return ans;
    }
};