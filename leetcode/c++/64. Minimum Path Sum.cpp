/*二维dp 
时间复杂度：O(MN)
空间复杂度：O(MN)
*/

//从下至上
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1]=dp[m-1][n]=0;
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};
//从上至下
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));


        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 && j==0)
                    dp[0][0]=grid[0][0];
                else if(i==0)
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                else if(j==0)
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

/*原地二维dp 
时间复杂度：O(MN)
空间复杂度：O(1)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 && j==0)
                    continue;
                else if(i==0)
                    grid[i][j] += grid[i][j-1];
                else if(j==0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        // 初始化
        for(int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0]; 
        for(int i = 1; i < n; i++)
            grid[0][i] += grid[0][i - 1]; 

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }

        return grid[m - 1][n - 1];
    }
};

/*一维dp 
时间复杂度：O(MN)
空间复杂度：O(N)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        vector<int> dp(n);
        // 初始化
        dp[0]=grid[0][0];

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) 
                    continue;
                else if(i == 0)
                    dp[j] = dp[j - 1] + grid[i][j];
                else if(j == 0)  
                    dp[j] += grid[i][j];
                else
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1];
    }
};
