class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, n=s.length();
        map<char, int> subMap;
        map<char, int>::iterator dup;
        
        for(int i=0, j=0; j<n; ++j){
            if((dup=subMap.find(s[j]))!=subMap.end())
                i=max(i, dup->second+1);
            ans=max(ans, j-i+1);
            subMap[s[j]]=j;
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sSize = s.length();
        unordered_map<char, int> hash;
        int res = 0;

        for(int i=0, j=0; j<sSize; ++j){
            //在容器中搜索键值等于 k 的元素，如果找到，则返回一个指向该元素的迭代器，
            //否则返回一个指向unordered_map :: end的迭代器。
            if((hash.find(s[j])) != hash.end())
            //取max是因为hash里存在的元素可能已经不在滑动窗口内，若不加会把i拉向滑动窗口前面的位置
                i = max(hash[s[j]]+1,i);
            res = max(j-i+1, res);
            hash[s[j]] = j;
        }
        return res;
    }
};