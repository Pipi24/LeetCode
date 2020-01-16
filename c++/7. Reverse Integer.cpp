//最初错误版本1
//理解错误的点在于不是限制了输入的范围就能保证不溢出，而是在翻转的时候可能溢出
class Solution {
public:
    int reverse(int x) {
		//参数类型就是int，这里想成绝对值不溢出了，大错特错
        if(x<=INT_MIN || x>INT_MAX)
            return 0;
        if(x<0)
            return -positive_reverse(abs(x));
        return positive_reverse(x);
    }
private:
    int positive_reverse(int x){
        int reminder = 0;
        int quotient = 0;
        int r_x = 0;
        while(x!=0){
            reminder = x%10;
            quotient = x/10;
            x = x/10;
			//乘10可能导致溢出，需要提前检查
            r_x = r_x*10+reminder;
        }
        return (int)r_x;
    }
};

/*标签：数学
本题如果不考虑溢出问题，是非常简单的。解决溢出问题有两个思路，第一个思路是通过字符串转换加try catch的方式来解决，第二个思路就是通过数学计算来解决。
由于字符串转换的效率较低且使用较多库函数，所以解题方案不考虑该方法，而是通过数学计算来解决。
通过循环将数字x的每一位拆开，在计算新值时每一步都判断是否溢出。
溢出条件有两个，一个是大于整数最大值MAX_VALUE，另一个是小于整数最小值MIN_VALUE，设当前计算结果为ans，下一位为pop。
从ans * 10 + pop > MAX_VALUE这个溢出条件来看
当出现 ans > MAX_VALUE / 10 且 还有pop需要添加 时，则一定溢出
当出现 ans == MAX_VALUE / 10 且 pop > 7 时，则一定溢出，7是2^31 - 1(2147483647)的个位数
从ans * 10 + pop < MIN_VALUE这个溢出条件来看
当出现 ans < MIN_VALUE / 10 且 还有pop需要添加 时，则一定溢出
当出现 ans == MIN_VALUE / 10 且 pop < -8 时，则一定溢出，8是-2^31(-2147483648)的个位数

作者：guanpengchn
链接：https://leetcode-cn.com/problems/reverse-integer/solution/hua-jie-suan-fa-7-zheng-shu-fan-zhuan-by-guanpengc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

class Solution {
public:
    int reverse(int x) {
        int reminder = 0;
        //int quotient = 0; 没用
        int r_x = 0;
        while(x!=0){
            reminder = x%10;
            //quotient = x/10; 没用
            x = x/10;
            if(r_x > INT_MAX/10 || r_x == INT_MAX/10 && reminder>7)
                return 0;
			//c++里，正数除法和负数除法的商和余数就是相反数
			//a=-19, a/10 ==-1, a%10 = -9
            if(r_x < INT_MIN/10 || r_x == INT_MIN/10 && reminder<-8)
                return 0;
            r_x = r_x*10+reminder;
        }
        return r_x;
    }
};
