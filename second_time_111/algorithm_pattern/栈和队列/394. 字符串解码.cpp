/*
这题看到括号的匹配，首先应该想到的就是用栈来解决问题。


方法一：栈操作
思路和算法

本题中可能出现括号嵌套的情况，比如 2[a2[bc]]，这种情况下我们可以先转化成 2[abcbc]，在转化成 abcbcabcbc。我们可以把字母、数字和括号看成是独立的 TOKEN，并用栈来维护这些 TOKEN。具体的做法是，遍历这个栈：

如果当前的字符为数位，解析出一个数字（连续的多个数位）并进栈
如果当前的字符为字母或者左括号，直接进栈
如果当前的字符为右括号，开始出栈，一直到左括号出栈，出栈序列反转后拼接成一个字符串，此时取出栈顶的数字（此时栈顶一定是数字，想想为什么？），就是这个字符串应该出现的次数，我们根据这个次数和字符串构造出新的字符串并进栈
重复如上操作，最终将栈中的元素按照从栈底到栈顶的顺序拼接起来，就得到了答案。注意：这里可以用不定长数组来模拟栈操作，方便从栈底向栈顶遍历。


*/
class Solution {
public:
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back()); 
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};

/*
用栈的方法一般可以使用递归栈来代替
递归思路和算法

我们也可以用递归来解决这个问题，从左向右解析字符串：

如果当前位置为数字位，那么后面一定包含一个用方括号表示的字符串，即属于这种情况：k[...]：
我们可以先解析出一个数字，然后解析到了左括号，递归向下解析后面的内容，遇到对应的右括号就返回，此时我们可以根据解析出的数字 x 解析出的括号里的字符串 s'
  构造出一个新的字符串 x×s'；
我们把 k[...] 解析结束后，再次调用递归函数，解析右括号右边的内容。
如果当前位置是字母位，那么我们直接解析当前这个字母，然后递归向下解析这个字母后面的内容。

时间复杂度：记解码后得出的字符串长度为 SS，除了遍历一次原字符串 ss，我们还需要将解码后的字符串中的每个字符都拼接进答案中，故渐进时间复杂度为 O(S+∣s∣)，即 O(S)。
空间复杂度：若不考虑答案所占用的空间，那么就只剩递归使用栈空间的大小，这里栈空间的使用和递归树的深度成正比，最坏情况下为O(∣s∣)，故渐进空间复杂度为 O(∣s∣)。


*/

class Solution {
public:
    string src; 
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits(); 
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString(); 
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--) ret += str; 
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }
        
        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};

/*
解题思路
用两个栈，一个数字栈存放数字，一个字符串栈放字符串，遍历到']'时，弹出一个数字和到'['之间的字符组合
注意数字在两位以上时的处理和入栈时机
新的字符串要和原来的字符串拼接在一起

*/
class Solution
{
public:
    /*
     * 双栈处理，一个栈放数字，一个栈放字符串，然后逐个退栈后叠加到输出字符串中
     */
    string decodeString(string s)
    {
        vector<int> dataStk;
        vector<string> strStack;

        int num = 0;
        string strTemp = "";

        for (int i = 0; i < s.length(); ++i)
        {
            char temp = s[i];

            // 把当前累加的数字计算出来
            if (isdigit(temp))
            {
                num = num * 10 + temp - '0';
                continue;
            }

            // 叠加字符串
            if (isalpha(temp))
            {
                strTemp.push_back(temp);
                continue;
            }

            // 当出现“[”时处理数字和字符串，其中0和空串也要入栈，否则后面出栈就会出现不匹配问题
            if (temp == '[')
            {
                dataStk.push_back(num);
                num = 0;

                strStack.push_back(strTemp);
                strTemp = "";

                continue;
            }

            // 当遇到“]”时计算结果
            // 1、把数字出栈，根据数字输出字符串；2、字符串栈出栈，把当前的字符串累加上去
            if (temp == ']')
            {
                int count = dataStk.back();
                dataStk.pop_back();
                string resTemp = strTemp;
                for (int k = 1; k < count; k++)
                {
                    resTemp.append(strTemp);
                }

                strTemp = strStack.back() + resTemp;
                strStack.pop_back();
            }
        }

        return strTemp;
    }
};
