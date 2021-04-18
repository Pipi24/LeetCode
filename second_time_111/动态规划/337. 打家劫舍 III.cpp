/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> dp = robHelper(root);
        return max(dp[0], dp[1]);
    }
    vector<int> robHelper(TreeNode* root){
        if(!root) return vector<int>{0, 0};
        vector<int> dpLeft = robHelper(root->left);
        vector<int> dpRight = robHelper(root->right);
        int val1 = max(dpLeft[0], dpLeft[1]) + max(dpRight[0], dpRight[1]);
        int val2 = root->val + dpLeft[0] + dpRight[0];
        return vector<int>{val1, val2};
    }
};