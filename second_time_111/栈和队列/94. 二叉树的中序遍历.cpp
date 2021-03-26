/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
时间复杂度：O(N)
空间复杂度：O(N)

*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        stack<TreeNode* > s;
        TreeNode* currentNode =  root;
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