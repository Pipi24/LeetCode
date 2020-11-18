c++ string类提供 + 或 += 运算符来拼接字符串

拼接字符串时，运算符的两边可以
1. 都是 string 字符串
2. 一个 string 字符串和一个C风格的字符串
3. 一个 string 字符串和一个字符数组
4. 一个 string 字符串和一个单独的字符

时间复杂度：O(N)
空间复杂度：O(N)



class Solution {
public:
    string replaceSpace(string s) {
        //初始化默认是空字符串''
        string res;
        for(char c:s){
            if(c==' ')
                res+="%20";
            else
                res+=c;
        }
        return res;
    }
};

class Solution {
public:
    string replaceSpace(string s) {     //字符数组
        string array;   //存储结果
        
        for(auto &c : s){   //遍历原字符串
            if(c == ' '){
                array.push_back('%');
                array.push_back('2');
                array.push_back('0');
            }
            else{
                array.push_back(c);
            }
        }
        return array;
    }
};
