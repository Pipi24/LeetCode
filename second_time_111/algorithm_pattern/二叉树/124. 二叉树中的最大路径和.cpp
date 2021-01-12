/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
关键：
1. 用全局变量保存最大路径和
2. 辅助函数返回的是当前节点加上左 或 右子节点的路径和（只能是左或向，不能左右都加上，否则以该节点计算了三条边，不可能是路径）

时间复杂度：O(N), 每个节点访问一次
空间复杂度：O(N), 最坏情况高度等于节点数
*/
class Solution {
public:
    int max_sum = INT_MIN;
    // 此辅助函数计算的是经过父节点的情况，用全局遍历保存，因此返回值是当前节点的值加上左右子节点中的较大值，
    int getMaxSum(TreeNode* root){
        if(root==nullptr)
            return 0;
        //左子节点所能提供的最大值（只能是一边，不能两边都加上，否则不经过父节点）
        // 若提供了负值，则就不需要选择左节点，用0表示，测试用例[2,-1]
        int max_left = max(getMaxSum(root->left), 0);
        //同左子节点
        int max_right = max(getMaxSum(root->right), 0);
        //左右子节点最大值加上当前节点的值
        int include_root = root->val+max_left+max_right;
        max_sum = max(max_sum, include_root);
        // 关键，向父节点返回的是当前节点加上左右子节点中的较大值，
        return root->val+max(max_left,max_right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
            return 0;
        getMaxSum(root);
        return max_sum;
    }
};