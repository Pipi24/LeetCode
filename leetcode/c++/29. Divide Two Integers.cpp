/* 方法一思路：
由于不能使用乘法和除法和mod运算符，所以采用位运算的方式
例子（7和（-3））首先要先判断结果是正数还是负数，两个正数异或还是正数，两个负数异或是正数，一正一负异或是负数，这是因为
二进制
0 1 这两个异或是1 负数的最高位是1，正数的最高位是0，所以一正一负异或是负数
同理1 1 这两个异或是0 所有两个负数异或是正数
1、首先采用异或的方式判断结果的符号 （flag 符号标识位）
2、（7 = 3 + 3 + 1）是要求商，也就是求几个除数相加 <= 被除数（数量为最大）
3、最开始想到的就是循环，每循环一次，被除数都要减去除数，count（数量）加1，直到被除数小于除数
7 3
4 3
1 3
4、最后判断是否溢出，输出count * flag
这个容易超时，是因为当被除数特别大时，除数为1时，每次都是减1，时间复杂度过高
因此要进一步优化

方法二思路
在一的方法上进行优化，循环的每次都要减去一个除数，这样比较慢，所以每次循环都把除数乘以2， 数量也乘以2
举个例子
50 2（初始值）
48 4循环第一次
44 8循环第二次
36 16循环第三次
20 32循环第四次
'''
20 2
'''
为什么这样写，这是因为当被除数大的时，除数小的时候，每次循环除数乘以2，相当于多加了一倍的除数，这样比方法一来说时间是成倍的缩小，对于大的数来说更合适
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        //溢出只会在除数为-1时发生
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }

        int flag=1;
        if((dividend ^ divisor) < 0)
            flag=-1;
        
        long dividend_l = abs(dividend);
        long divisor_l = abs(divisor);
        
        int ans = 0;
        if(dividend_l<divisor_l)
            return ans;
        while(dividend_l>=divisor_l){
            //不改变divisor_l，用以大于dividend_l时重新从divisor_l扩大
            long tmp = divisor_l;
            //记录divisor_l的次数
            long count = 1;
            while(dividend_l>=tmp){
                dividend_l-=tmp;
                ans += count;
                //不能用乘法
                tmp = tmp+tmp;
                //tmp<<=1;
                count = count +count;
                //count<<=1;
            }
        }
        return flag>0?ans:-ans;

    }
};