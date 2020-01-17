class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<2)
            return s;
        int begin = 0,  end = 0;
        for(int i=0; i<s.length(); ++i){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len > end-begin+1){
                begin = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(begin, end-begin+1);
    }
private:
	//string传引用减少内存消耗
    int expand(const string& s, int left, int right){
        int l = left, r = right;
        //多扩了2
        while(l >= 0 && r < s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return r - l- 1;
    }
};