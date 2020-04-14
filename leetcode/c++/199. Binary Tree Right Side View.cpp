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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; ++i){
                TreeNode* tmp=q.front();
                q.pop();
                if(i==len-1)
                    ans.push_back(tmp->val);
                if(tmp->left!=nullptr)
                    q.push(tmp->left);
                if(tmp->right!=nullptr)
                    q.push(tmp->right);
            }
        }
        return ans;
    }
};

//先加右节点，则不用判断i==len-1
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            ans.push_back(q.front()->val);
            int len = q.size();
            for(int i=0; i<len; ++i){
                TreeNode* tmp= q.front();
                q.pop();
                if(tmp->right!=nullptr)
                    q.push(tmp->right);
                if(tmp->left!=nullptr)
                    q.push(tmp->left);
                
            }
        }
        return ans;
    }
};
//递归解法