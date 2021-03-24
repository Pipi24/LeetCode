class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));
        int cur = 1;
        int maxNum = n * n;
        int curRow = 0, curCol = 0;
        int d = 0;
        vector<vector<int> > directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(cur<=maxNum){
            ans[curRow][curCol] = cur;
            int nextRow = curRow + directions[d][0], nextCol = curCol + directions[d][1];
            if(nextRow<0 || nextRow>=n || nextCol<0 || nextCol>=n || ans[nextRow][nextCol])
                d = (d + 1) % 4;
            curRow += directions[d][0];
            curCol += directions[d][1];
            cur++;
        }
        return ans;
    }
};