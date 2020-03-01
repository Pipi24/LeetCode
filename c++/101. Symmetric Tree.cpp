/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right) {
        if(left==nullptr && right==nullptr)
            return true;
        if(left!=nullptr && right!=nullptr){
            if(left->val == right->val)
                return helper(left->left, right->right) && helper(left->right, right->left);
            return false;
        }
        return false;
    }
};

//利用栈或者队列消除递归

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
    bool isSymmetric(TreeNode* root) {
         if(root==nullptr)
            return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty()){
            TreeNode* n1 = s.top();
            s.pop();
            TreeNode* n2 = s.top();
            s.pop();
            if(n1==nullptr && n2==nullptr)
                continue;
            if(n1!=nullptr && n2!=nullptr && n1->val == n2->val){
                s.push(n1->left);
                s.push(n2->right);
                s.push(n1->right);
                s.push(n2->left);

            }
            else
                return false;

        }
        return true;
    }
};