//动态规划
//dp[i][j]表示数组A[i:]和数组B[j:]的最长公共前缀
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
//滑动窗口
//A对齐B或反之，探寻每一种对齐可能
class Solution {
public:
    int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
        int ret = 0, k = 0;
        for (int i = 0; i < len; i++) {
            if (A[addA + i] == B[addB + i]) {
                k++;
            } else {
                k = 0;
            }
            ret = max(ret, k);
        }
        return ret;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int len = min(m, n - i);
            int maxlen = maxLength(A, B, i, 0, len);
            ret = max(ret, maxlen);
        }
        for (int i = 0; i < m; i++) {
            int len = min(n, m - i);
            int maxlen = maxLength(A, B, 0, i, len);
            ret = max(ret, maxlen);
        }
        return ret;
    }
};
