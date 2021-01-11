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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(root == nullptr)
            return ret;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()){
            int level_size = que.size();
            double level_sum = 0.0;
            for(int i=0; i<level_size; ++i){
                level_sum += que.front()->val;
                if(que.front()->left!=nullptr)
                    que.push(que.front()->left);
                if(que.front()->right!=nullptr)
                    que.push(que.front()->right);
                que.pop();
            }
            ret.push_back(level_sum/level_size);
        }
        return ret;
    }
};