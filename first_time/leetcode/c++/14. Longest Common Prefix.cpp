class Solution {
public:
     string longestCommonPrefix(vector<string>& strs) {
        string s = "";

        //长度为0直接返回空字符串
        if(strs.size() == 0) {
            return s;
        }

        //minLen是最短字符串长度
        int minLen = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < minLen){
                minLen = strs[i].size();
            }
        }

        for(int i = 0; i < minLen; i++){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(ch != strs[j][i]){
                    return s;
                }
            }
            s += ch;
        }
        return s;
    }
};

/*
首先，假设有两个单词 "abcd"和"abcde"，那么在一本涵盖了所有字母排列的字典中，
这两个单词之间的单词也一定有前缀"abcd"（可以看做26进制的数）
于是，我们就只需要比较最小字典序的字符串和最大字典序的字符串
那么sort一遍数组，然后取strs[0]与strs[n-1],比较求解即可
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
		// 最初的版本就是直接遍历找最大与最小的，但是和sort时间消耗无差异，因此为了题解代码的简洁性与可读性，就用了sort
        sort(strs.begin(),strs.end());
        for(int i = 0;i < min(strs[0].length(),strs[n-1].length());i++){
            if(strs[0][i] != strs[n-1][i]) return strs[0].substr(0,i);
        }
        return strs[0];
    }
};
