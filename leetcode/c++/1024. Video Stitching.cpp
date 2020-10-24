/*
方法一：动态规划
思路及解法

比较容易想到的方法是动态规划，我们令 dp[i] 表示将区间 [0,i) 覆盖所需的最少子区间的数量。由于我们希望子区间的数目尽可能少，因此可以将所有dp[i] 的初始值设为一个大整数，并将 dp[0]（即空区间）的初始值设为 0。

我们可以枚举所有的子区间来依次计算出所有的 dp 值。我们首先枚举 i，同时对于任意一个子区间 [a_j,b_j)，若其满足 a_j < i <= b_j
 ，那么它就可以覆盖区间 [0, i)[0,i) 的后半部分，而前半部分则可以用 \textit{dp}[a_j]dp[a 
j
​   
 ] 对应的最优方法进行覆盖，因此我们可以用 dp[a_j] + 1dp[a 
j
​   
 ]+1 来更新 \textit{dp}[i]dp[i]。状态转移方程如下：

dp[i]=min{dp[a_j]}+1  (a_j<=i<=b_j)

最终的答案即为 dp[T]。

时间复杂度：O(T×N)，其中 T 是区间的长度，N 是子区间的数量。
空间复杂度：O(T)，其中 T 是区间的长度。
*/
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            for (auto& it : clips) {
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};

/*
方法二：贪心
思路及解法

注意到对于所有左端点相同的子区间，其右端点越远越有利。且最佳方案中不可能出现两个左端点相同的子区间。于是我们预处理所有的子区间，对于每一个位置 i，我们记录以其为左端点的子区间中最远的右端点，
记为 maxn[i]。

我们可以参考「55. 跳跃游戏的官方题解」，使用贪心解决这道题。

具体地，我们枚举每一个位置，假设当枚举到位置 i 时，记左端点不大于 i 的所有子区间的最远右端点为 last。这样 last 就代表了当前能覆盖到的最远的右端点。

每次我们枚举到一个新位置，我们都用 maxn[i] 来更新 last。如果更新后 last==i，那么说明下一个位置无法被覆盖，我们无法完成目标。

同时我们还需要记录上一个被使用的子区间的结束位置为 pre，每次我们越过一个被使用的子区间，就说明我们要启用一个新子区间，这个新子区间的结束位置即为当前的 last。也就是说，
每次我们遇到 i==pre，则说明我们用完了一个被使用的子区间。这种情况下我们让答案加 1，并更新 pre 即可。

时间复杂度：O(T+N)，其中 T 是区间的长度，N 是子区间的数量。我们需要枚举每一个位置，时间复杂度 O(T)，同时我们还需要预处理所有的子区间，时间复杂度 O(N)。总时间复杂度为O(T)+O(N)=O(T+N)。

空间复杂度：O(T)，其中 T 是区间的长度。对于每一个位置，我们需要记录以其为左端点的子区间的最右端点。


*/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T);
        int last = 0, ret = 0, pre = 0;
        for (vector<int>& it : clips) {
            if (it[0] < T) {
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        for (int i = 0; i < T; i++) {
            last = max(last, maxn[i]);
            if (i == last) {
                return -1;
            }
            if (i == pre) {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/video-stitching/solution/shi-pin-pin-jie-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。