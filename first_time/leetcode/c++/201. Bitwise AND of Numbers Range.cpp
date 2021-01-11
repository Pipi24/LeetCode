/*
位移
这些二进制字符串的公共前缀也即指定范围的起始和结束数字 m 和 n 的公共前缀（即在上面的示例中分别为 9 和 12）。

因此，最终我们可以将问题重新表述为：给定两个整数，我们要找到它们对应的二进制字符串的公共前缀。


*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift=0;
        while(m<n){
            m>>=1;
            n>>=1;
            shift++;
        }
        return m<<shift;
    }
};

/*
Brian Kernighan 算法
还有一个位移相关的算法叫做「Brian Kernighan 算法」，它用于清除二进制串中最右边的 1。

Brian Kernighan 算法的关键在于我们每次对 number 和number−1 之间进行按位与运算后，number 中最右边的 1 会被抹去变成 0。
连续两个数最后一位按位与的结果必是0

基于上述技巧，我们可以用它来计算两个二进制字符串的公共前缀。

其思想是，对于给定的范围 [m,n]（m<n），我们可以对数字 n 迭代地应用上述技巧，清除最右边的 1，直到它小于或等于 m，此时非公共前缀部分的 1 均被消去。因此最后我们返回 n 即可


*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};
