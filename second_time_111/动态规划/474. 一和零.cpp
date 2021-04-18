class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(string str : strs){
            int zeroNum = 0, oneNum = 0;
            for(char c : str){
                if(c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }
            for(int j = m; j >= zeroNum; --j){
                for(int k = n; k>=oneNum; --k){
                    dp[j][k] = max(dp[j-zeroNum][k-oneNum]+1, dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};