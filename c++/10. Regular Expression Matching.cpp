//递归version1
class Solution {
public:
    bool isMatch(string s, string p) {
    if(s.size()==0 && p.size() == 0)
        return true;
    if(s.size()!=0 && p.size()==0)
        return false;
    return match(s, p, 0, 0);
    }
    bool match(string& s, string& p, int s_i, int p_i){
        //等于size是为了保证s和p都已经遍历完，若是size-1则最后一个没有判断
        //除此之外，要注意先判断p再判断s，因为s遍历完时p仍有可能匹配(a,ab*)
        if(p_i==p.size()){
            if(s_i==s.size())
                return true;
            else
                return false;
        }
        bool one = false, zero = false;
        //如果第2个位置是‘*’
        if((p[p_i+1]=='*')&&(p_i+1<p.size())){
            zero = match(s, p, s_i, p_i+2); //匹配0次
            if(!zero && (s_i<s.size()) && (s[s_i] == p[p_i] || p[p_i]=='.')){
                //|| match(s, p, s_i+1, p_i+2) //匹配1次
                one = match(s, p, s_i+1, p_i); //匹配多次
            }
            return zero || one;
            //else
                //s和p中的字符没有匹配，此时‘*’只能匹配0次
                //return match(s, p, s_i, p_i+2); //只能匹配0次
        }
        else{
            if((s_i<s.size()) && (s[s_i] == p[p_i] || p[p_i]=='.')){
                return match(s, p, s_i+1, p_i+1);//只能匹配一次
            }
            else
                return false;
        }
    }
};


//递归version2
class Solution {
public:
    bool isMatch(string s, string p) {
    if(s.size()==0 && p.size() == 0)
        return true;
    if(s.size()!=0 && p.size()==0)
        return false;
    return match(s, p, 0, 0);
    }
    bool match(string& s, string& p, int s_i, int p_i){
        //等于size是为了保证s和p都已经遍历完，若是size-1则最后一个没有判断
        //除此之外，要注意先判断p再判断s，因为s遍历完时p仍有可能匹配(a,ab*)
        if(p_i==p.size()){
            if(s_i==s.size())
                return true;p
            else
                return false;
        }
        //如果第2个位置是‘*’, p_i+1<p.size()这个条件不影响，因为上面其实已经判断出p_i<p.size()
        if(p_i+1<p.size() && p[p_i+1]=='*'){
            //注意s_i<s.size()必须要有,因为s_i多次调用又不加检查会产生数组下标溢出
            if((s_i<s.size()) && (s[s_i] == p[p_i] || p[p_i]=='.')){
                return match(s, p, s_i, p_i+2) //匹配0次
                //|| match(s, p, s_i+1, p_i+2) //匹配1次，可要可不要，因为已经被0次和多次的情况包含
                || match(s, p, s_i+1, p_i); //匹配多次
            }
            else
                //s和p中的字符没有匹配，此时‘*’只能匹配0次
                return match(s, p, s_i, p_i+2); //只能匹配0次
        }
        else{
            if((s_i<s.size()) && (s[s_i] == p[p_i] || p[p_i]=='.')){
                return match(s, p, s_i+1, p_i+1);//只能匹配一次
            }
            else
                return false;
        }
    }
};

//DP
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0 && p.size() == 0)
            return true;
        if(s.size()!=0 && p.size()==0)
            return false;

        //dp[i][j]表示前i个源字符与前j个模式串字符是否匹配（含当前i,j这两个字符）
        //多的一行一列用以表达s或p为空串的时候
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        //都为空串，匹配
        dp[0][0]=true;
        //初始化s为空串，p仍可能匹配的情况，s="",p="a*b*"
        //j从2开始是因为：1)dp[0][0]已经初始化;2)dp[0][1]不可能匹配，默认为false
        for(int j=2; j<=p.size(); ++j){
            //j-1为'*'才有可能匹配
            if(p[j-1]=='*')
                //s为空串，匹配0次
                dp[0][j] = dp[0][j-2];
        }

        for(int i=1; i<=s.size();++i){
            //j从1开始是因为p为空，s不为空时不可能匹配
            for(int j=1; j<=p.size();++j){
                //j>1时才有可能进行带'*'匹配
                if(j>1 && p[j-1]=='*'){
                    //前面一个字符匹配的话就可0次或者多次匹配，否则只能0次匹配
                    if(s[i-1]==p[j-2] || p[j-2]=='.')
                        dp[i][j] = dp[i][j-2] || dp[i-1][j]; //0次或者多次
                    else
                        dp[i][j]=dp[i][j-2];
                }
                else if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                //初始化为false，可以不再写其他不匹配的情况了
            }
        }
        return dp[s.size()][p.size()];
    }
};
