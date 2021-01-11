class Solution {
public:

    unordered_map<char, char> um = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
    };

    bool isValid(string s) {
        if (s.empty()) {
            return true;
        } else if (s.size() % 2) {
            return false;
        } else {
            stack<char> ss;
            for (int i = 0; i < s.size(); i ++) {
                if (ss.empty()) {
                    ss.push(s[i]);
                } else {
                    if (s[i] == um[ss.top()]) {
                        ss.pop();
                    } else {
                        ss.push(s[i]);
                    }
                }
            }
            return ss.empty();
        }        
    }
};