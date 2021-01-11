class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word: A) {
            fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};
/*
根据题目的要求，如果字符 cc 在所有字符串中均出现了 kk 次及以上，那么最终答案中需要包含 kk 个 cc。因此，我们可以使用 \textit{minfreq}[c]minfreq[c] 存储字符 cc 在所有字符串中出现次数的最小值。

我们可以依次遍历每一个字符串。当我们遍历到字符串 ss 时，我们使用 \textit{freq}[c]freq[c] 统计 ss 中每一个字符 cc 出现的次数。在统计完成之后，我们再将每一个 \textit{minfreq}[c]minfreq[c] 更新为其本身与 \textit{freq}[c]freq[c] 的较小值。这样一来，当我们遍历完所有字符串后，\textit{minfreq}[c]minfreq[c] 就存储了字符 cc 在所有字符串中出现次数的最小值。

由于题目保证了所有的字符均为小写字母，因此我们可以用长度为 2626 的数组分别表示 \textit{minfreq}minfreq 以及 \textit{freq}freq。

在构造最终的答案时，我们遍历所有的小写字母 cc，并将 \textit{minfreq}[c]minfreq[c] 个 cc 添加进答案数组即可。
*/