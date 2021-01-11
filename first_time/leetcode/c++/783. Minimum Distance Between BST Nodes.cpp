/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> inOrder;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            inOrder.emplace_back(cur->val);
            s.pop();
            cur = cur->right;
        }
        int res = INT_MAX;
        for(int i=1; i<inOrder.size();++i){
            res = min(res, inOrder[i]-inOrder[i-1]);
        }
        return res;
    }
};