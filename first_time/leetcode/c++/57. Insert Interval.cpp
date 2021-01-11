/*
前言
对于区间 S_1 = [l_1, r_1]和 S_2 = [l_2, r_2], 如果它们之间没有重叠（没有交集），说明要么 S_1在 S_2的左侧，此时有 r_1 < l_2；要么 S_1在 S_2的右侧，此时有 l_1 > r_2
如果 r_1 < l_2和 l_1 > r_2二者均不满足，说明 S_1和 S_2必定有交集，它们的交集即为

[\max(l_1, l_2), \min(r_1, r_2)]

并集即为

[\min(l_1, l_2), \max(r_1, r_2)]

思路与算法

在给定的区间集合 X 互不重叠的前提下，当我们需要插入一个新的区间 S=[left,right] 时，我们只需要：

找出所有与区间 S 重叠的区间集合 X′；将 X′中的所有区间连带上区间 S 合并成一个大区间；
最终的答案即为不与X′重叠的区间以及合并后的大区间。

这样做的正确性在于，给定的区间集合中任意两个区间都是没有交集的，因此所有需要合并的区间，就是所有与区间 S 重叠的区间。

并且，在给定的区间集合已经按照左端点排序的前提下，所有与区间 S 重叠的区间在数组 intervals 中下标范围是连续的，因此我们可以对所有的区间进行一次遍历，就可以找到这个连续的下标范围。
当我们遍历到区间 [l_i, r_i]时：如果 r_i < left，说明 [l_i, r_i]与 S 不重叠并且在其左侧，我们可以直接将 [l_i, r_i]加入答案；

如果 l_i > right，说明 [l_i, r_i]与 S 不重叠并且在其右侧，我们可以直接将 [l_i, r_i]加入答案；

如果上面两种情况均不满足，此时，我们需要将 S 与 [l_i, r_i]合并，即将 S 更新为其与 [l_i, r_i]的并集。

那么我们应当在什么时候将区间 S 加入答案呢？由于我们需要保证答案也是按照左端点排序的，因此当我们遇到第一个 满足 l_i > right的区间时，说明以后遍历到的区间不会与 S 重叠，并且它们左端点一定会大于 S 的左端点。
此时我们就可以将 S 加入答案。特别地，如果不存在这样的区间，我们需要在遍历结束后，将 S 加入答案。

*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            // 在插入区间的右侧且无交集
            if (interval[0] > right) {
                // newInterval还未插入
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        // 遍历完还未插入，表示newInterval在区间最右边
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
