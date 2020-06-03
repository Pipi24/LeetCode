/*
方法一：暴力法
思路

我们可以生成所有 2^{2n}2 
2n
  个 '(' 和 ')' 字符构成的序列，然后我们检查每一个是否有效即可。

算法

为了生成所有序列，我们可以使用递归。长度为 n 的序列就是在长度为 n-1 的序列前加一个 '(' 或 ')'。

为了检查序列是否有效，我们遍历这个序列，并使用一个变量 balance 表示左括号的数量减去右括号的数量。如果在遍历过程中 balance 的值小于零，或者结束时 balance 的值不为零，那么该序列就是无效的，否则它是有效的。

*/
class Solution {
    bool valid(const string& str) {
        int balance = 0;
        for (char c : str)
            if (c == '(')
                ++balance;
            else {
                --balance;
                if (balance < 0)
                    return false;
            }
        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current))
                result.push_back(current);
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};
/*
方法二：回溯法

回溯算法也叫试探法,它是一种系统地搜索问题的解的方法。回溯算法的基本思想是:从一条路往前走,能进则进,不能进则退回来,换一条路再试。


思路和算法

方法一还有改进的余地：我们可以只在序列仍然保持有效时才添加 '(' or ')'，而不是像 方法一 那样每次添加。我们可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点，

如果左括号数量不大于 nn，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。

判断回溯很简单，拿到一个问题，你感觉如果不穷举一下就没法知道答案，那就可以开始回溯了。

一般回溯的问题有三种：

Find a path to success 有没有解
Find all paths to success 求所有解
求所有解的个数
求所有解的具体信息
Find the best path to success 求最优解
回溯法是一个剪枝了的二叉树。我们要得到的结果是可以 good leaf，如果不满足 good leaf 就继续向下搜索，搜索的时候需要满足一定的条件。

*/
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
