/*
此题与 面试题14- I. 剪绳子 主体等价，唯一不同在于本题目涉及 “大数越界情况下的求余问题” 。
建议先做上一道题，在此基础上再研究此题目的大数求余方法。

*/
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        
        if (remainder == 0) {
            return quickPow(3, quotient, 1);
        } else if (remainder == 1) {
            return quickPow(3, quotient - 1, 4);
        } else {
            return quickPow(3, quotient, 2);
        }
    }
    /*
    循环求幂
    a^1,a^2,a^3,...,a^n
    时间复杂度 O(N)、每一步取余保证不溢出
    */
    long long forPow(long long a,long long n,int mul){
        long long res = 1;
        int mod = 1e9+7;
        for(int i=1; i<=n; ++i){
            res = (res * a)%mod;
        }
        res = (res*mul)%mod;
        return (int)(res);
    }
    /*
    快速幂，将底数扩大平方倍，幂数降低平方倍，若幂数为奇数，多乘一个底数
    参见https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/

    幂是奇数先乘一个a
    时间复杂度 O(log_2^N) ： 其中 N=a ，二分法为对数级别复杂度，每轮仅有求整、求余、次方运算。
    求整和求余运算：资料提到不超过机器数的整数可以看作是 O(1)；
    幂运算：查阅资料，提到浮点取幂为 O(1) 。
    空间复杂度 O(1) ： 变量 a, b, p, x, rem 使用常数大小额外空间。

    */
   long long quickPow(long long a,long long n,int mul){
        long long res = 1;
        int mod = 1e9+7;
        while(n>0){
            //位运算，表示奇数
            if(n&1)
                res = (res*a)%mod;
            a = (a*a)%mod;
            //右移一位
            n>>=1;
        }

        res = (res*mul)%mod;
        return (int)(res);
    }

};
/*

*/