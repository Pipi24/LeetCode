/*
同一个数出现三次，那么每个二进制位上求和一定是0或者3，于是统计所有数字每一个位的和，余3的结果就是出现一次的数字，再恢复移位

时间复杂度：O(32N)
空间复杂度：O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; ++i){
            // 统计每位1的个数
            int sum = 0;
            for(int num: nums){
                // 统计1的个数
                sum += (num>>i)&1;
            }
            // 还原位00^10=10 或者用| 也可以
            res ^= (sum%3)<<i;
        }
        return res;
    }
};