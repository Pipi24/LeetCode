/* hash+堆

首先遍历整个数组，并使用哈希表记录每个数字出现的次数，并形成一个「出现次数数组」。找出原数组的前 k个高频元素，就相当于找出「出现次数数组」的前 k 大的值。

最简单的做法是给「出现次数数组」排序。但由于可能有 O(N) 个不同的出现次数（其中 N 为原数组长度），故总的算法复杂度会达到 O(NlogN)，不满足题目的要求。

在这里，我们可以利用堆的思想：建立一个小顶堆，然后遍历「出现次数数组」：

如果堆的元素个数小于 k，就可以直接插入堆中。
如果堆的元素个数等于 k，则检查堆顶与当前出现次数的大小。如果堆顶更大，说明至少有 k 个数字的出现次数比当前值大，故舍弃当前值；否则，就弹出堆顶，并将当前值插入堆中。
遍历完成后，堆中的元素就代表了「出现次数数组」中前  k 大的值。




时间复杂度：O(Nlogk)，其中 NN 为数组的长度。我们首先遍历原数组，并使用哈希表记录出现次数，每个元素需要 O(1) 的时间，共需 O(N) 的时间。
随后，我们遍历「出现次数数组」，由于堆的大小至多为 k，因此每次堆操作需要 O(logk) 的时间，共需 O(Nlogk) 的时间。二者之和为 O(Nlogk)。
空间复杂度：O(N)。哈希表的大小为 O(N)，而堆的大小为 (k)，共计为 O(N) */

class Solution {
struct cmp1{ 
    bool operator ()(pair<int, int>&a, pair<int, int>&b){ 
        return a.second>b.second;//最小值优先 
    } 
}; 

public:
    static bool cmp2(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        // 第一个参数是元素类型，第二个是元素容器类型，第三个是比较函数
        // decltype参见 http://c.biancheng.net/view/438.html
        //大小顶堆底层数据结构就是数组

        //priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp2)> q(cmp2);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};