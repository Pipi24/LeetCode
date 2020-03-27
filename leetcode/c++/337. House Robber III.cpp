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
    vector<int> robDp(TreeNode* root){
        //返回数组第一位为包含根节点最大值，第二位为不包含根节点最大值
        if (root == nullptr)
            return{0, 0};
        vector<int> left = robDp(root->left);//左子树的信息
        vector<int> right = robDp(root->right);//右子树的信息
        vector<int> temp(2, 0);
        temp[0] = root->val + left[1]+right[1];//包含根节点的最大值
        temp[1] = max(left[0], left[1]) + max(right[0],right[1]);//不包含根节点的最大值
        return temp;
    }
    
    int rob(TreeNode* root) {
        if (root == nullptr)return 0;
	    vector<int> ans;
	    ans = robDp(root);
	    return max(ans[0], ans[1]);
    }
};