//动态规划 f[i][j]表示前i个数划分成j段的最大连续子数组和的最小值

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};

//二分+贪心

class Solution {
public:
    bool check(vector<int>& nums, int x, int m) {
        //当前正在划分的子数组的和
        long long sum = 0;
        //已经划分的子数组的数量
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > x) {
                //超过给定的二分值时，需要把当前取的值nums[i]作为新的一段分割子数组的开头
                //并将 cnt 加 1。遍历结束后验证是否 cnt 不超过 m，未超过的话说明该x能满足题意
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        //left下界是nums中单个元素的最大值
        //right上界是nums中所有元素的和
        for (int i = 0; i < nums.size(); i++) {
            right += nums[i];
            if (left < nums[i]) {
                left = nums[i];
            }
        }
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (check(nums, mid, m)) {
                //mid能满足题意，继续缩小，减小上界
                right = mid;
            } else {
                //mid不能满足题意，扩大，增加下界
                left = mid + 1;
            }
        }
        //返回最后的界限
        return left;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/split-array-largest-sum/solution/fen-ge-shu-zu-de-zui-da-zhi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。