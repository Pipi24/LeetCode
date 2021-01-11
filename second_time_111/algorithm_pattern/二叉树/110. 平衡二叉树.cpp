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
 1. 自顶向下递归
 判断左、右子树是否平衡，会对所有节点遍历一次
 判断当前节点是否平衡，会遍历所有节点一次

 时间复杂度：O(N^2)，同一个节点的高度会被重复调用（叶子节点被调用了N次）
 空间复杂度：O(N)，递归的次数为2*N
 */
class Solution {
public:
    int getDepth(TreeNode* root){
        if(root==nullptr)
            return 0;
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(getDepth(root->left)-getDepth(root->right))<=1;
    }
};
/*
2. 自底向上的递归
方法1中，同一个节点的getDepth会被重复调用，导致时间复杂度较高。如果使用自底向上的做法，则对于每个节点，getDepth 只会被调用一次。

Key：用-1代表不平衡，才能实现getDiffDepth既能表示平衡与否，也能返回树的高度
 时间复杂度：O(N)
 空间复杂度：O(N)
*/

class Solution {
public:
    int getDepth(TreeNode* root){
        if(root==nullptr)
            return 0;
        int left=getDepth(root->left);
        int right=getDepth(root->right);
        //左子树不平衡or右子树不平衡or当前节点不平衡，用-1表示
        if(left==-1 || right==-1 || abs(left-right)>1)
            return -1;
        //否则平衡，返回高度
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root)>=0;
    }
};