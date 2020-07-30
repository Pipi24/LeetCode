/*
就是剪绳子

dp[i]表示数字i在第j位分成两段的乘积
要么不再继续拆分(i-j)*j
要么继续拆分(i-j)*dp[j]
dp[i] = max(dp[i], max((i-j)*j, (i-j)*dp[j]))

2可以表示为1 1
dp[2] = max(max((2-1)*1, (2-1)*dp[1]))

3可以表示为 1 1 1
dp[3] = max(max((3-1)*1, (3-1)*dp[1]), max((3-2)*1, (3-2)*dp[2]))

时间复杂度O(n^2)
空间复杂度O(n)
*/


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);

        dp[1]=1;
        for(int i=2; i<=n; ++i){
            for(int j=1; j<i; ++j){
                dp[i] = max(dp[i], max((i-j)*j, (i-j)*dp[j]));
            }
        }
        return dp[n];
    }
};

/*
利用数学知识降低时间复杂度
上述方法的j是根据i遍历的，由数学知识可以证明，在乘积最大的条件下，j只能取2或3，因此
dp[i] = max(max((i-2)*2, dp[i-2]*2), max((i-3)*3, dp[i-3]*3))

时间复杂度O(n)
空间复杂度O(n)
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n<4)
            return n-1;
        
        vector<int> dp(n+1, 0);

        dp[1]=1;
        dp[2]=1;
        for(int i=3; i<=n; ++i){
                dp[i] = max(max((i-2)*2, dp[i-2]*2), max((i-3)*3, dp[i-3]*3));
        }
        return dp[n];
    }
};
/*
方法二中利用了数学知识降低时间复杂度。正整数 4 可以拆分成 2+2，乘积不变（4=2×2）。对于大于 4 的正整数，
总是存在一种拆分的方案，使得拆分成的两个正整数的乘积大于拆分前的正整数（例如，5=2+3，2×3=6>5）。那么，能否利用数学知识在方法二的基础上进一步降低时间复杂度，找到最优的拆分方案呢？
证明参见：https://leetcode-cn.com/problems/integer-break/solution/zheng-shu-chai-fen-by-leetcode-solution/

时间复杂度O(1)
空间复杂度O(1)

*/

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int)pow(3, quotient);
        } else if (remainder == 1) {
            return (int)pow(3, quotient - 1) * 4;
        } else {
            return (int)pow(3, quotient) * 2;
        }
    }
};
