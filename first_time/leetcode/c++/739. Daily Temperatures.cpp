/*
单调栈

维护一个递减的栈，存储当前还没有找到比栈内元素大的温度对应的下标

每当一个新的温度进来，判断它与栈顶元素的大小，若大于栈顶元素，则弹出栈顶元素，将栈顶元素在答案数组中的值改为i-previousIndex
继续判断栈顶元素和当前温度的关系，直到栈为空或者栈顶元素不再小于当前元素
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
