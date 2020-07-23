/*
二维dp
dp[i][j]表示s1的前i个字符和s2的前j个字符是否能组成s3的前i+j个字符
dp[i][j] = (dp[i-1][j] && s3[i+j-1]==s1[i-1]) || (dp[i][j-1] && s3[i+j-1]==s2[j-1])
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ss1 = s1.size(), ss2 = s2.size(), ss3 = s3.size();
        if(ss1 + ss2 != ss3)
            return false;

        vector<vector<int> >dp(ss1+1, vector<int>(ss2+1, false));
        for(int i=0; i<=ss1; ++i){
            for(int j=0; j<=ss2; ++j){
                if(i==0 && j==0){
                    dp[i][j] = true;
                    continue;
                }
                    
                if(i>0 && s3[i+j-1]==s1[i-1])
                    dp[i][j] |= dp[i-1][j];
                if(j>0 && s3[i+j-1]==s2[j-1])
                    dp[i][j] |= dp[i][j-1];
            }
        }
        return dp[ss1][ss2];
    }
};

/*
滚动数组 一维空间dp 常用技巧 只与上一行状态有关

if(i > 0 && s3[i + j - 1] == s1[i - 1])
      dp[i][j] = dp[i - 1][j];
应该改为
if(i > 0 && s3[i + j - 1] != s1[i - 1])
      dp[j] = false;
因为 如果s3[i + j - 1] == s1[i - 1]，则无需改变，但不等的话需要设为false
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ss1 = s1.size(), ss2 = s2.size(), ss3 = s3.size();
        if(ss1 + ss2 != ss3)
            return false;

        vector<int> dp(ss2+1, false);
        dp[0] = true;

        for(int i=0; i<=ss1; ++i){
            for(int j=0; j<=ss2; ++j){
                    
                if(i>0 && s3[i+j-1]!=s1[i-1])
                    dp[j] = false;
                if(j>0 && s3[i+j-1]==s2[j-1])
                    dp[j] |= dp[j-1];
            }
        }
        return dp[ss2];
    }
};
