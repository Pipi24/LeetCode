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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        stack<TreeNode* > s;
        TreeNode* currentNode =  root;
		//currentNode!=nullptr条件是第一次进入循环时栈为空
        while(!s.empty() || currentNode!=nullptr){
            while(currentNode!=nullptr){
                s.push(currentNode);
                currentNode=currentNode->left;
            }
            currentNode = s.top();
            s.pop();
            ans.push_back(currentNode->val);
            currentNode = currentNode->right;
        }
        return ans;
    }
};