/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;

        if (!root) return res;
        stk.push(root);

        while (stk.size())
        {
            auto t = stk.top();
            stk.pop();

            res.push_back(t->val);
            for (int i = t->children.size() - 1; ~i; i -- ) //从最后一个儿子节点往前遍历
                stk.push(t->children[i]);
        }

        return res;
    }
};
