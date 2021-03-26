/*
// BFS 从0进队列，弹出之后计算上下左右的结果，将上下左右重新进队列进行二层操作
// 0 0 0 0
// 0 x 0 0
// x x x 0
// 0 x 0 0

// 0 0 0 0
// 0 1 0 0
// 1 x 1 0
// 0 1 0 0

// 0 0 0 0
// 0 1 0 0
// 1 2 1 0
// 0 1 0 0
时间复杂度：O(rc)，其中 r 为矩阵行数，c 为矩阵列数，即矩阵元素个数。广度优先搜索中每个位置最多只会被加入队列一次，因此只需要 O(rc) 的时间复杂度。

空间复杂度：O(rc)，其中 r 为矩阵行数，c 为矩阵列数，即矩阵元素个数。除答案数组外，最坏情况下矩阵里所有元素都为 0，全部被加入队列中，此时需要 O(rc) 的空间复杂度。

*/
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                }
                else
                    matrix[i][j]=-1;
            }
        }

        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj]==-1) {
                    matrix[ni][nj] = matrix[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }

        return matrix;
    }
};


/*
DP
https://leetcode-cn.com/problems/01-matrix/solution/01ju-zhen-by-leetcode-solution/
*/