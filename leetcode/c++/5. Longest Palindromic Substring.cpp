//中心扩展
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

//DP
class Solution {
public:
    string longestPalindrome(string s) {
        int sSize = s.size();
        if(sSize < 2)
            return s;
        
        //dp[i][j]表示i~j是否是回文
        vector<vector<int>> dp(sSize, vector<int>(sSize,0));
        
        int start = 0;
        int end = 0;
        //初始化一个和两个字符为回文时的情况
        for(int i=0; i<sSize; ++i){
            dp[i][i]=1;
            if(i<sSize-1 && s[i]==s[i+1]){
                dp[i][i+1] = 1;
                start=i;
                end=start+1;
            }
        }
        //然后找到所有三字母回文，并依此类推…
        for(int l=3;l<=sSize;l++){//l表示检索的子串长度，等于3表示先检索长度为3的子串
            for(int i=0;i+l-1<sSize;i++){
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1){//状态转移
                    dp[i][j]=1;
                    start=i;
                    end=j;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};