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
private:
    vector<int> ans;
    vector<int> inorder;
    int max_count = 0;
    int now_count = 0;
public:
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr)
            return ans;
        stack<TreeNode*> s;
        TreeNode* top_node=root;
        while(top_node!=nullptr || !s.empty()){

            while(top_node!=nullptr){
                s.emplace(top_node);
                top_node=top_node->left;
            }
            top_node = s.top();
            inorder.emplace_back(top_node->val);
            s.pop();
            top_node = top_node->right;
        }
        for(int i=0; i<inorder.size(); ++i){
            if(i==0){
                max_count=now_count=1;
                ans.emplace_back(inorder[i]);
                continue;
            }
            now_count = inorder[i]==inorder[i-1]?now_count+1:1;
            if(now_count==max_count)
                ans.emplace_back(inorder[i]);
            else if(now_count>max_count){
                ans = vector<int>(1, inorder[i]);
                max_count=now_count;
            }
        }
        return ans;

    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        cnt = (root->val == val) ? cnt + 1 : 1;
        if (cnt == maxcnt) {
            ans.push_back(root->val);
        }
        else if (cnt > maxcnt) {
            maxcnt = cnt;
            ans = vector<int>(1, root->val);
        }
        val = root->val;

        inorder(root->right);
    }

private:
    int val = INT_MIN;
    int cnt = 0;
    int maxcnt = 0;
    vector<int> ans;
};
