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
    int dfs(TreeNode* root, int parent_sum){
        if(root==nullptr)
            return parent_sum;
        int right_sum = dfs(root->right, parent_sum);
        root->val += right_sum;
        //找到右子树的最左边节点
        return dfs(root->left, root->val);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};

//反向中序遍历
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
    int sum=0;

    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        convertBST(root->right);
        sum += root->val;
        root->val=sum;
        convertBST(root->left);
        return root;
    }
};

