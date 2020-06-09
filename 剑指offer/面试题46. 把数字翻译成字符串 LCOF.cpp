/*
方法一
动态规划
f(i)表示以第 i 位结尾的前缀串翻译的方案数
f(i)=f(i−1)+f(i−2) if (i−1≥0,10≤x≤25)
f(i)=f(i−1) else if (i−1≥0)
https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-by-leetcode-sol/
*/
class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q; 
            q = r; 
            r = 0;
            r += q;
            if (i == 0) {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {
                r += p;
            }
        }
        return r;
    }
};



/*
方法二

递归
1.每次取最后两位数,rem = num % 100
2.若rem > 25,则无法表示,即rem的个位和十位无法合一起，则用translateNum(num/10),表示前进一位
3.若在00 <= rem <= 09,则无法表示，即rem的个位和十位无法合一起，所以用translateNum(num/10)
如num = 506,其只有一种表示为fag,不可表示为fg，所以0是无法和6组合一起成为06
4.若在10 <= rem <= 25,则可以分出两种表示方法,所以用translateNum(num/10) + translateNum(num/100)递归来计算数量
5.所以总结以上就是：
if (num < 10),则加1
if (num%100 < 10 || num%100 > 25) translateNum(num/10);
if (10 <= num % 100 <= 25) translateNum(num/10) + translateNum(num/100);

链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/cjian-ji-dai-ma-shuang-bai-by-orangeman/

*/
class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        return (num%100 < 10 || num%100 > 25) ? translateNum(num/10) : translateNum(num/10) + translateNum(num/100);
    }
};

作者：OrangeMan
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/cjian-ji-dai-ma-shuang-bai-by-orangeman/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。