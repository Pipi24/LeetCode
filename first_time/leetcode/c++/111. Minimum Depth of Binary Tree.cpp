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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(root->left==nullptr && root->right==nullptr)
            return 1;
        int left = INT_MAX, right = INT_MAX;
        if(root->left!=nullptr)
            left = minDepth(root->left);
        if(root->right!=nullptr)
            right = minDepth(root->right);
        return min(left, right) + 1;
    }
};