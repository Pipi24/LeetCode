/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //要先找到后面的节点才能用前面的节点指向它
 //迭代
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            if(temp->right!=nullptr)
                s.push(temp->right);
            if(temp->left!=nullptr)
                s.push(temp->left);
            temp->left = nullptr;
            if(s.empty())
                temp->right = nullptr;
            else
                temp->right = s.top();
        }
    }
};

//递归
class Solution {
private:
    //prev是递归时先访问的点，即结果中靠后的点
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
};