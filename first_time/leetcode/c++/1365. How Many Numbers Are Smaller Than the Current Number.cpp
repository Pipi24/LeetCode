/*
我们也可以将数组排序，并记录每一个数在原数组中的位置。对于排序后的数组中的每一个数，我们找出其左侧第一个小于它的数，这样就能够知道数组中小于该数的数量。

时间复杂度：O(NlogN)，其中 N 为数组的长度。排序需要O(NlogN) 的时间，随后需要 O(N) 时间来遍历。
空间复杂度：O(N)。因为要额外开辟一个数组。

*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> data;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> ret(n, 0);
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (prev == -1 || data[i].first != data[i - 1].first) {
                prev = i;
            }
            ret[data[i].second] = prev;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> data;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> ret(n, 0);
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (data[i].first != data[i - 1].first) {
                prev = i;
            }
            ret[data[i].second] = prev;
        }
        return ret;
    }
};


/*
注意到数组元素的值域为 [0,100]，所以可以考虑建立一个频次数组 cnt ，cnt[i] 表示数字 i 出现的次数。那么对于数字i 而言，小于它的数目就为cnt[0...i−1] 的总和。

时间复杂度：O(N+K)，其中 K 为值域大小。需要遍历两次原数组，同时遍历一次频次数组 cnt 找出前缀和。
空间复杂度：O(K)。因为要额外开辟一个值域大小的数组。


*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
        }
        return ret;
    }
};
