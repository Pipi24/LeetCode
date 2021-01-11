前言
当我们计算出每个点到原点的欧几里得距离的平方后，本题和「剑指 Offer 40. 最小的k个数」是完全一样的题。

为什么是欧几里得距离的「平方」？这是因为欧几里得距离并不一定是个整数，在进行计算和比较时可能会引进误差；但它的平方一定是个整数，这样我们就无需考虑误差了。

方法一：排序
思路和算法

将每个点到原点的欧几里得距离的平方从小到大排序后，取出前 K 个即可。

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        });
        return {points.begin(), points.begin() + K};
    }
};
时间复杂度：O(nlogn)，其中 n 是数组 points 的长度。算法的时间复杂度即排序的时间复杂度。

空间复杂度：O(logn)，排序所需额外的空间复杂度为 O(logn)。


方法二：优先队列
思路和算法

我们可以使用一个优先队列（大根堆）实时维护前 KK 个最小的距离平方。

首先我们将前 K 个点的编号（为了方便最后直接得到答案）以及对应的距离平方放入优先队列中，随后从第 K+1 个点开始遍历：如果当前点的距离平方比堆顶的点的距离平方要小，就把堆顶的点弹出，再插入当前的点。
当遍历完成后，所有在优先队列中的点就是前 K 个距离最小的点。

不同的语言提供的优先队列的默认情况不一定相同。在 C++ 语言中，优先队列即为大根堆，但在 Python 语言中，优先队列为小根堆，因此我们需要在优先队列中存储（以及比较）距离平方的相反数。
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int n = points.size();
        for (int i = K; i < n; ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < q.top().first) {
                q.pop();
                q.emplace(dist, i);
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};
复杂度分析

时间复杂度：O(nlogK)，其中 nn 是数组 points 的长度。由于优先队列维护的是前 K 个距离最小的点，因此弹出和插入操作的单次时间复杂度均为 O(logK)。在最坏情况下，数组里 n 个点都会插入，因此时间复杂度为 O(nlogK)。

空间复杂度：O(K)，因为优先队列中最多有 K 个点。


方法三：快速选择（快速排序的思想）
思路和算法

我们也可以借鉴快速排序的思想。

快速排序中的划分操作每次执行完后，都能将数组分成两个部分，其中小于等于分界值 \textit{pivot}pivot 的元素都会被放到左侧部分，而大于 \textit{pivot}pivot 的元素都都会被放到右侧部分。与快速排序不同的是，在本题中我们可以根据 KK 与 \textit{pivot}pivot 下标的位置关系，只处理划分结果的某一部分（而不是像快速排序一样需要处理两个部分）。

我们定义函数 random_select(left, right, K) 表示划分数组 points 的 [left,right] 区间，并且需要找到其中第 K 个距离最小的点。
在一次划分操作完成后，设 pivot 的下标为 i，即区间 [left,i−1] 中的点的距离都小于等于 pivot，而区间 [i+1,right] 的点的距离都大于 pivot。此时会有三种情况：

如果 K=i−left+1，那么说明 pivot 就是第 K 个距离最小的点，我们可以结束整个过程；

如果 K<i−left+1，那么说明第 K 个距离最小的点在 pivot 左侧，因此递归调用 random_select(left, i - 1, K)；

如果 K>i−left+1，那么说明第 K 个距离最小的点在 pivot 右侧，因此递归调用 random_select(i + 1, right, K - (i - left + 1))。

在整个过程结束之后，第 KK 个距离最小的点恰好就在数组 points 中的第 KK 个位置，并且其左侧的所有点的距离都小于它。此时，我们就找到了前 K 个距离最小的点。
class Solution {
private:
    mt19937 gen{random_device{}()};

public:
    void random_select(vector<vector<int>>& points, int left, int right, int K) {
        int pivot_id = uniform_int_distribution<int>{left, right}(gen);
        int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
        swap(points[right], points[pivot_id]);
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivot) {
                ++i;
                swap(points[i], points[j]);
            }
        }
        ++i;
        swap(points[i], points[right]);
        // [left, i-1] 都小于等于 pivot, [i+1, right] 都大于 pivot
        if (K < i - left + 1) {
            random_select(points, left, i - 1, K);
        }
        else if (K > i - left + 1) {
            random_select(points, i + 1, right, K - (i - left + 1));
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        random_select(points, 0, n - 1, K);
        return {points.begin(), points.begin() + K};
    }
};
时间复杂度：期望为 O(n)O(n)，其中 nn 是数组 \textit{points}points 的长度。
空间复杂度：期望为 O(\log n)O(logn)，即为递归调用的期望深度。