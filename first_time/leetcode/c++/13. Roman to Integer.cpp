
/*
解题思路
通过观察我们发现，只有在遇到特殊情况时，两个字符中左边的字符小于右边的字符，且等于右边的字符代表的数减左边字符代表的数。 比如 CM 等于 1000 - 1001000−100，XC 等于 100 - 10100−10...

因此，我们将 字符：数值 存在 Roman2Int 的哈希表中。然后从左到右遍历每个字符，如果 s[i] < s[i+1]，就将结果减去 s[i] 代表的数字；否则，将结果加上 s[i] 代表的数字。

*/
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> roman={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D', 500},
            {'M', 1000}
        };//初始化哈希表
        for(int i=0;i<s.length();i++)
        {
            if(roman[s[i]] < roman[s[i+1]])
                result -= roman[s[i]];
            else
            {
                result += roman[s[i]];
            }
        }
        return result;
    }
};