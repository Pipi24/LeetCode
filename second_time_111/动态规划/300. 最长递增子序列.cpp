//时间复杂度O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};

/*时间复杂度O(NlogN)
1. 排序后求LCS，时间O(n^2)，空间O(n)

2. dp[i]存储A[:i]的LIS，每个i和前面的下标对比，时间O(n^2)，空间O(n)

for j in [i-1, 0]:

  if A[j]<A[i]:

    dp[i] = max(dp[i], dp[j]+1)

3. dp[i]存储LIS为i+1时最大的值，最后len(dp)即为答案，时间O(nlogn)，空间O(n)

二分法查找插入dp的位置
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]是LIS长度为i+1时末位元素的最小值
        vector<int> dp(nums.size(), 0);
        int len = 0;
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(dp[len] < nums[i]){
                len += 1;
                dp[len] = nums[i];
            }
            else{
                int l = 0, r = len;
                while(l < r){
                    int m = l + ((r - l) / 2);
                    if(nums[i] > dp[m])
                        l = m + 1;
                    else
                        r = m;
                } 
                //dp[r] = nums[i]; or
                dp[l] = nums[i];
            }
        }
        return len + 1;
    }
};