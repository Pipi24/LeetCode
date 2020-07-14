/*自顶向下，列从左到右
时间复杂度：O(n^2)，其中 nn 是三角形的行数。

空间复杂度：O(n^2)。我们需要一个 n*nn∗n 的二维数组存放所有的状态。

*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};

/*自顶向下，列从右到左
时间复杂度：O(n^2)，其中 nn 是三角形的行数。

空间复杂度：O(n)。
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};

/*自底向上
时间复杂度：O(n^2)，其中 n 是三角形的行数。

空间复杂度：O(n)。
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //最后一行
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i --)
            for(int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};