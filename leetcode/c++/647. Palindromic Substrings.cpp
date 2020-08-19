/*
枚举回文中心，每扩展一次，回文数量加1
一共2n-1个中心，奇数和偶数两种回文情况
时间：O(N^2)
空间：O(1)
*/

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


/*
Malacca
manacher的时间复杂度不明白的可以看看这个，讲得很清楚： https://segmentfault.com/a/1190000008484167
时间：O(N)
空间：O(N)
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
};

/*
DP
用 dp 数组来进行动态规划, dp[i][len] 表示从 i 开始的长度为 len 的子串是否是回文子串, 那么 dp[i][len] = dp[i + 1][len - 2] && s[i] == s[i + len - 1], 以此来动态规划即可, 其实和中心扩散本质是一样的, 都是从小区间向大区间扩散


*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int ans = n;
        //从 i 开始的长度为 len 的子串是否是回文子串
        vector<vector<bool>>dp(n, vector<bool>(n + 1, false));
        for(int i = 0; i < n; i ++){
            dp[i][0] = true;
            dp[i][1] = true;
        }
        for(int len = 2; len <= n; len ++){
            for(int i = 0; i <= n - len; i ++){
                if(i + 1 < n && dp[i + 1][len - 2] && s[i] == s[i + len - 1]){
                    ans ++; 
                    dp[i][len] = true;
                }
            }
        }
        return ans;
    }
};
