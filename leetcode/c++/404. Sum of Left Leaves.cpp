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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr)
            return 0;

        int left_sum = sumOfLeftLeaves(root->left);
        int right_sum = sumOfLeftLeaves(root->right);
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
            return root->left->val+left_sum+right_sum;
        else
            return left_sum+right_sum;
    }
};