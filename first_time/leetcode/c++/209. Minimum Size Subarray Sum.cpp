/*

定义两个指针 start 和 end 分别表示子数组的开始位置和结束位置，维护变量 sum 存储子数组中的元素和（即从 nums[start] 到 nums[end] 的元素和）。

初始状态下，start 和 end 都指向下标 0，sum 的值为 0。

每一轮迭代，将 nums[end] 加到 sum，如果sum≥s，则更新子数组的最小长度（此时子数组的长度是 end−start+1），然后将nums[start] 从sum 中减去并将 start 右移，
直到 sum<s，在此过程中同样更新子数组的最小长度。在每一轮迭代的最后，将end 右移。


*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
