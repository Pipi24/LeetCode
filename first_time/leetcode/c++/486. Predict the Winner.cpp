/* 为了判断哪个玩家可以获胜，需要计算一个总分，为先手得分与后手得分之差。当数组中的所有数字都被拿取时，如果总分大于或等于 0，则先手获胜，反之则后手获胜。

由于每次只能从数组的任意一端拿取数字，因此可以保证数组中剩下的部分一定是连续的。假设数组当前剩下的部分为下标 start 到下标 end，其中 0≤start≤end<nums.length。
如果 start=end，则只剩一个数字，当前玩家只能拿取这个数字。如果 start<end，则当前玩家可以选择 nums[start] 或 nums[end]，然后轮到另一个玩家在数组剩下的部分选取数字。这是一个递归的过程。

计算总分时，需要记录当前玩家是先手还是后手，判断当前玩家的得分应该记为正还是负。当数组中剩下的数字多于 1 个时，当前玩家会选择最优的方案，使得自己的分数最大化，
因此对两种方案分别计算当前玩家可以得到的分数，其中的最大值为当前玩家最多可以得到的分数

时间复杂度：O(2^n)，其中 n 是数组的长度。

空间复杂度：O(n)，其中 n 是数组的长度。空间复杂度取决于递归使用的栈空间。 */


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }

    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
        /* 要是把第一轮的turn当成=1的先手的话，那么第二轮的turn就是-1是后手的那个。
        后手的情况因为*turn的乘上去的是一个负数，所以在最大值比较的时候其实应该比较他们为正的情况（后手也需要使自己的分数最大，所以选绝对值最大的方案）
        （就好比两个负数比大小要比较绝对值的大小才知道哪一个更小这种感觉），然后取了那个大的值后，还需要返回为turn=-1的情况，所以又在最外面乘了一个turn~ */
        return max(scoreStart * turn, scoreEnd * turn) * turn;
    }
};
/* 
动态规划
方法一使用递归，存在大量重复计算，因此时间复杂度很高。由于存在重复子问题，因此可以使用动态规划降低时间复杂度。

定义二维数组 dp，其行数和列数都等于数组的长度，dp[i][j] 表示当数组剩下的部分为下标 i 到下标 j 时，当前玩家与另一个玩家的分数之差的最大值，注意当前玩家不一定是先手。

只有当i≤j 时，数组剩下的部分才有意义，因此当 i>j 时，dp[i][j]=0。

当 i=j 时，只剩一个数字，当前玩家只能拿取这个数字，因此对于所有 0≤i<nums.length，都有 dp[i][i]=nums[i]。

当 i<j 时，当前玩家可以选择 nums[i] 或 nums[j]，然后轮到另一个玩家在数组剩下的部分选取数字。在两种方案中，当前玩家会选择最优的方案，使得自己的分数最大化。因此可以得到如下状态转移方程：

dp[i][j]=max(nums[i]−dp[i+1][j],nums[j]−dp[i][j−1])

最后判断dp[0][nums.length−1] 的值，如果大于或等于 0，则先手得分大于或等于后手得分，因此先手成为赢家，否则后手成为赢家。

时间复杂度：O(N^2)
空间复杂度：O(N^2)
 */

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size()));
        for(int i=0; i<nums.size(); ++i){
            dp[i][i] = nums[i];
        }
        for(int i=nums.size()-2; i>=0; --i){
            for(int j=i+1; j<nums.size(); ++j){
                dp[i][j]=max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][nums.size()-1]>=0;
    }
};

/* dp空间的优化
上述代码中使用了二维数组 dp。分析状态转移方程可以看到，dp[i][j] 的值只和dp[i+1][j] 与dp[i][j−1] 有关，即在计算 dp 的第 i 行的值时，只需要使用到 dp 的第 i 行和第 i+1 行的值，
因此可以使用一维数组代替二维数组，对空间进行优化。
时间复杂度：O(N^2)
空间复杂度：O(N)
class Solution { */
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i=0; i<nums.size(); ++i){
            dp[i] = nums[i];
        }
        for(int i=nums.size()-2; i>=0; --i){
            for(int j=i+1; j<nums.size(); ++j){
                dp[j]=max(nums[i]-dp[j], nums[j]-dp[j-1]);
            }
        }
        return dp[nums.size()-1]>=0;
    }
};

