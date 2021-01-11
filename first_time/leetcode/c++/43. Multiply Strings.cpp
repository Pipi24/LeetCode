/* 竖式乘法
模拟手算乘法，乘数num2从后到前每一位与被乘数num1相乘结果再相加，注意补0

时间复杂度：O(mn+n^2)，其中 m 和 n 分别是 num1和num2的长度。需要从右往左遍历 num2 ，对于nu2的每一位，都需要和 num1的每一位计算乘积，因此计算乘积的总次数是 mn。
字符串相加操作共有 n 次，相加的字符串长度最长为 m+n，因此字符串相加的时间复杂度是 O(mn+n^2)。总时间复杂度是 O(mn+n^2)。

空间复杂度：O(m+n)O。空间复杂度取决于存储中间状态的字符串，由于乘积的最大长度为 m+n，因此存储中间状态的字符串的长度不会超过 m+n。 */


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            //后面补0
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            //第一位仍有进位
            if (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            //数字转字符
            for (auto &c : curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }

    string addStrings(string &num1, string &num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};
/* 做乘法
num2的从后往前每一位分别与num1的每一位相乘，用n+m长的数组保存结果，num1[i]*num2[j]的结果放在ansArr[i+j+1]的位置上，最后去掉前导0（若有）
时间复杂度：O(mn)
时间复杂度：O(m+n)
参考：

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};
