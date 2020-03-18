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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n==0)
            return ans;
        return help(1, n);
    }
    vector<TreeNode*> help(int start, int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=start; i<=end; ++i){
            vector<TreeNode*> left =  help(start, i-1);
            vector<TreeNode*> right =  help(i+1, end);
            for(int j=0; j<left.size(); ++j){
                for(int k=0; k<right.size(); ++k){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};