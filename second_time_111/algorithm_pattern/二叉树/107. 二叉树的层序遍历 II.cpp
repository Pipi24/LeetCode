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
102. 二叉树的层序遍历得到结果反转一下，reverse复杂度为线性O(N)
关键：使用队列保存每一层的节点，每一层先求队列size
时间复杂度：O(N)，每个节点遍历一次
空间复杂度：O(N)，高度等于节点数, reverse复杂度为线性O(N)
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            //这里要先保存size,不能在循环是求size,因为会有元素增删引起改变
            int num_layer = q.size();
            vector<int> node_layer;
            while(num_layer){
                TreeNode* front = q.front();
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                node_layer.push_back(front->val);
                num_layer--;
            }
            res.push_back(node_layer);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
