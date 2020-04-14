/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //中序遍历是否为递增序列
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        stack<TreeNode* > s;
        while(root!=nullptr){
            s.push(root);
            root = root->left;
        }
        //测试用例有大于int范围的数
        long pre = LONG_MIN;
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            if(cur->val<=pre)
                return false;
            pre = cur->val;
            if(cur->right!=nullptr){
                cur = cur->right;
                while(cur!=nullptr){
                    s.push(cur);
                    cur = cur->left;
                }
            }
        }
        return true;
    }
};