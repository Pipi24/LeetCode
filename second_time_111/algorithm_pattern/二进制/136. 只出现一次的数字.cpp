/*
常见二进制操作
基本操作
a=0^a=a^0
0=a^a
由上面两个推导出：a=a^b^b
交换两个数
a=a^b
b=a^b
a=a^b
移除最后一个 1
a=n&(n-1)
获取最后一个 1
diff=(n&(n-1))^n
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int num: nums)
            //res = res^num;
            res ^= num;

        return res;
    }
};