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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while(!s.empty()||cur!=nullptr){
            if(cur!=nullptr && cur->left!=nullptr){
                s.push(cur);
                TreeNode* left = cur->left;
                cur->left = nullptr;
                cur = left;
            }
            else if(cur!=nullptr &&cur->right!=nullptr){
                s.push(cur);
                TreeNode* right = cur->right;
                cur->right = nullptr;
                cur = right;
            }
            else if(cur!=nullptr && cur->left==nullptr && cur->right==nullptr){
                ans.push_back(cur->val);
                cur = s.empty()?nullptr:s.top();
                s.pop();
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root)    st.push(root);
        while(!st.empty()){
            root=st.top();
            if(root->right)  st.push(root->right);
            if(root->left)  st.push(root->left);
            if(!root->left && !root->right){
                ans.push_back(root->val);
                st.pop();
            }
            root->left=root->right=NULL;
        }
        return ans;
    }
};
