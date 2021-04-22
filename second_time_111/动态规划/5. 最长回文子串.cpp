class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int max_len = 1;
        int start = 0;
        vector<vector<int> > dp(size, vector<int>(size, false));
        for(int i = 0; i < size - 1 ; ++i){
            dp[i][i] = true;
            int j = i + 1;
            if(j < size && s[i] == s[j])
                dp[i][j] = true;
                if(dp[i][j] && j - i + 1 > max_len){
                    start = i;
                    max_len = j - i + 1;
                }
                    
        }
            
        for(int i = size - 3; i >= 0; --i){
            for(int j = i + 2; j < size; ++j){
                if(s[i] == s[j] && dp[i+1][j-1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
                if(dp[i][j] && (j - i + 1 > max_len)){
                    start = i;
                    max_len = j - i + 1;
                }
                    
            }
        }
        return s.substr(start, max_len);
    }
};


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