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
1. 双向队列，一层从后进，下一层从反方向进
时间复杂度：O(N)，每个节点访问一次
空间复杂度：O(N)，高度等于节点数
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool is_from_left = true;
        while(!q.empty()){
            int layer_num = q.size();
            // 双向队列，一层从后进，下一层从反方向进
            deque<int> layer_val;
            while(layer_num){
                TreeNode* front = q.front();
                q.pop();
                if(is_from_left)
                    layer_val.push_back(front->val);
                else
                    layer_val.push_front(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                layer_num--;
            }
            // 类型转换
            res.push_back(vector<int>{layer_val.begin(), layer_val.end()});
            is_from_left = !is_from_left;
        }
        return res;
    }
};

/*
1. 是否需要反转某一层的结果
时间复杂度：O(N)，每个节点访问一次
空间复杂度：O(N)，高度等于节点数
*/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool is_from_left = true;
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
            //是否需要反转某一层的结果
            if(!is_from_left)
                reverse(node_layer.begin(), node_layer.end());
            res.push_back(node_layer);
            is_from_left = !is_from_left;
        }
        //reverse(res.begin(), res.end());
        return res;
    }
};