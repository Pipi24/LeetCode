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


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            //如果右节点为空或者已经访问
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                //记录上一个访问的节点
                prev = root;
                //当前节点已经访问，需要重置root
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};
