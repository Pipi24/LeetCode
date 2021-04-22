class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int> > dp(size, vector<int>(size, 0));
        for(int i = 0; i < size; ++i)
            dp[i][i] = 1;
        for(int i = size - 1; i >= 0; --i){
            for(int j = i + 1; j < size; ++j){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][size - 1];
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};