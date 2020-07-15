/*
时间复杂度：O((N−L)L)，其中 N 为 haystack 字符串的长度，L 为 needle 字符串的长度。内循环中比较字符串的复杂度为 L，总共需要比较 (N - L) 次。

空间复杂度：O(1)。

*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;

        int h_len = haystack.size();
        int n_len = needle.size();

        for(int i=0; i<=h_len-n_len; ++i){
            int k=i;
            int j=0;
            while(haystack[k]==needle[j] && j<n_len){
                k++;
                j++;
            }
            if(j==n_len)
                return i;
            
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;

        int h_len = haystack.size();
        int n_len = needle.size();

        int h_idx=0;
        while(h_idx <= h_len-n_len){
            //第一个字符匹配
            while(h_idx<h_len && haystack[h_idx] != needle[0])
                h_idx++;
            
            int n_idx = 0, match_len=0;
            while(h_idx<h_len && n_idx<n_len && haystack[h_idx] == needle[n_idx]){
                h_idx++;
                n_idx++;
                match_len++;
            }
            if(match_len == n_len)
                return h_idx-match_len;
            h_idx = h_idx-match_len+1;
        }
        return -1;
    }
};