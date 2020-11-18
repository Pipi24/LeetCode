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


如果想把这道题目做到极致，就不要只用额外的辅助空间了！

首先扩充数组到每个空格替换成"%20"之后的大小。

然后从后向前替换空格，也就是双指针法，过程如下：

i指向新长度的末尾，j指向旧长度的末尾。

从前向后填充就是O(n^2)的算法了，因为每次添加元素都要将添加元素之后的所有元素向后移动。

其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。

这么做有两个好处：

不用申请新数组。
从后向前填充元素，避免了从前先后填充元素要来的 每次添加元素都要将添加元素之后的所有元素向后移动。
时间复杂度：O(n)
空间复杂度：O(1)

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0; // 统计空格的个数
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // 从后先前将空格替换为"%20"
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

