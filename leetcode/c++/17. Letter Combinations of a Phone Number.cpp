class Solution {
public:
    unordered_map<char,string> dmap = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"qprs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
    int len = digits.size();
    if(!len) return {};
    vector<string> ans;
    if(len==1) {
        string str = dmap[digits[0]];
        int len = str.size();
        int i;
        string tmp = "";
        for(i=0;i<len;i++){
			//不能直接push字面值
            ans.push_back(tmp+str[i]);
        }
        return ans;
    }
    else{
        vector<string> last = letterCombinations(digits.substr(1,len-1));
        string strthis = dmap[digits[0]];
        int lenthis = strthis.size();
        int lenlast = last.size();
        int j,k;
        for(j = 0; j<lenthis;j++){
            for(k = 0;k<lenlast;k++){
                ans.push_back(strthis[j]+last[k]);
            }
        }
        return ans;
    }

    }
};

作者：luo-zhang-hui-xian
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-zu-he-di-gui-fa-shuang-100-by-luo-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        map<char,string> m={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}
        };
        vector<vector<string>> dp;
        for(int i=0;i<m[digits[0]].size();i++)
        {
            string s;
            s.push_back(m[digits[0]][i]);
            ans.push_back(s);
        }
        dp.push_back(ans);     
        for(int i=1;i<digits.size();i++)
        {
            ans.clear();
            for(int k=0;k<m[digits[i]].size();k++)
            {
                for(int j=0;j<dp[i-1].size();j++)
                {
                    string s=dp[i-1][j];
                    s.push_back(m[digits[i]][k]);
                    ans.push_back(s);
                }
            }
            dp.push_back(ans);
        }
        return dp[digits.size()-1];   
    }
};

作者：asdy-s
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dong-tai-gui-hua-jie-fa-by-asdy-s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/* DFS+回溯

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode-solutio/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};

