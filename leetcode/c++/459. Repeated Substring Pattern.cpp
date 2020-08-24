/*
枚举
时间复杂度：O(N^2)
空间复杂度：O(1)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i) {
            if (n % i == 0) {
                bool match = true;
                for (int j = i; j < n; ++j) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
字符串匹配
首先问题可以转化为：我们将两个 s 连在一起，并移除第一个和最后一个字符。如果 s 是该字符串的子串，那么 s 就满足题目要求。正确性证明见
https://leetcode-cn.com/problems/repeated-substring-pattern/solution/zhong-fu-de-zi-zi-fu-chuan-by-leetcode-solution/

*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

/* 
KMP算法
http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

在方法二中，我们使用了语言自带的字符串查找函数。同样我们也可以自己实现这个函数，例如使用比较经典的 KMP 算法。

读者需要注意以下几点：

KMP 算法虽然有着良好的理论时间复杂度上限，但大部分语言自带的字符串查找函数并不是用 KMP 算法实现的。这是因为在实现 API 时，我们需要在平均时间复杂度和最坏时间复杂度二者之间权衡。普通的暴力匹配算法以及优化的 BM 算法拥有比 KMP 算法更为优秀的平均时间复杂度；

学习 KMP 算法时，一定要理解其本质。如果放弃阅读晦涩难懂的材料（即使大部分讲解 KMP 算法的材料都包含大量的图，但图毕竟只能描述特殊而非一般情况）而是直接去阅读代码，是永远无法学会 KMP 算法的。读者甚至无法理解 KMP 算法关键代码中的任意一行。

由于本题就是在一个字符串中查询另一个字符串是否出现，可以直接套用 KMP 算法。因此这里对 KMP 算法本身不再赘述。读者可以自行查阅资料进行学习。这里留了三个思考题，读者可以在学习完毕后尝试回答这三个问题，检验自己的学习成果：

1. 设查询串的的长度为 n，模式串的长度为 m，我们需要判断模式串是否为查询串的子串。那么使用 KMP 算法处理该问题时的时间复杂度是多少？在分析时间复杂度时使用了哪一种分析方法？
答：时间复杂度为 O(n+m)，用到了均摊分析（摊还分析）的方法。具体地，无论在预处理过程还是查询过程中，虽然匹配失败时，指针会不断地根据 fail 数组向左回退，看似时间复杂度会很高。
但考虑匹配成功时，指针会向右移动一个位置，这一部分对应的时间复杂度为 O(n+m)。又因为向左移动的次数不会超过向右移动的次数，因此总时间复杂度仍然为 O(n+m)。


2. 如果有多个查询串，平均长度为 nn，数量为 kk，那么总时间复杂度是多少？
答：时间复杂度为 O(nk+m)O(nk+m)。模式串只需要预处理一次。

3. 在 KMP 算法中，对于模式串，我们需要预处理出一个 \textit{fail}fail 数组（有时也称为 \textit{next}next 数组、\piπ 数组等）。这个数组到底表示了什么？
答：fail[i] 等于满足下述要求的 xx 的最大值：s[0:i]s[0:i] 具有长度为 x+1x+1 的完全相同的前缀和后缀。这也是 KMP 算法最重要的一部分。

时间复杂度：O(N)
空间复杂度：O(N)

 */
class Solution {
public:
    bool kmp(const string& query, const string& pattern) {
        int n = query.size();
        int m = pattern.size();
        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        int match = -1;
        for (int i = 1; i < n - 1; ++i) {
            while (match != -1 && pattern[match + 1] != query[i]) {
                match = fail[match];
            }
            if (pattern[match + 1] == query[i]) {
                ++match;
                if (match == m - 1) {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp(s + s, s);
    }
};
/* 
KMP优化
如果读者能够看懂「正确性证明」和「思考题答案」这两部分，那么一定已经发现了方法三中的 KMP 算法有可以优化的地方。即：

在「正确性证明」部分，如果我们设 i 为最小的起始位置，那么一定有 gcd(n,i)=i，即 n 是 i 的倍数。这说明字符串 s 是由长度为 i 的前缀重复 n/i次构成；

由于 fail[n−1] 表示 s 具有长度为fail[n−1]+1 的完全相同的（且最长的）前缀和后缀。那么对于满足题目要求的字符串，一定有 fail[n−1]=n−i−1，即 i=n−fail[n−1]−1；

对于不满足题目要求的字符串，n 一定不是 n−fail[n−1]−1 的倍数。

上述所有的结论都可以很容易地使用反证法证出。

因此，我们在预处理出fail 数组后，只需要判断 n 是否为 n−fail[n−1]−1 的倍数即可。


 */
class Solution {
public:
    bool kmp(const string& pattern) {
        int n = pattern.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        return fail[n - 1] != -1 && n % (n - fail[n - 1] - 1) == 0;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp(s);
    }
};

