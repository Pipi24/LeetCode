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
1. 按照定义，找到左子树最大值，右子树最小值，与根比较，在递归左子树和右子树
时间复杂度 : O(n^2)，叶子节点最坏会被访问N次，总共N个节点，所以N^2
空间复杂度 : O(n)，高度等于节点数，递归左右子节点
*/

class Solution {
public:
    /* 返回右子树当中的最小值 */
    int minValueNode(struct TreeNode* node)
    {
        struct TreeNode* current = node;

        /*一直向左走，找到最小值*/
        while (current && current->left != NULL)
            current = current->left;

        return current->val;
    }

    /* 返回左子树当中的最大值 */
    int maxValueNode(struct TreeNode* node)
    {
        struct TreeNode* current = node;

        /*一直向左走，找到最大值*/
        while (current && current->right != NULL)
            current = current->right;

        return current->val;
    }

    bool isValidBST(struct TreeNode* root){
        if(root == NULL) return true;
        //当前节点是否满足
        if(root->left != NULL && maxValueNode(root->left) >= root->val) return false;
        if(root->right != NULL && minValueNode(root->right) <= root->val) return false;

        //左右子树是否满足
        if(!isValidBST(root->left) || !isValidBST(root->right)) return false;
        return true;
    }

};


/*
2. 递归
关键：helper函数的意义
时间复杂度 : O(n)，其中 n 为二叉树的节点个数。
空间复杂度 : O(n)，高度等于节点数
*/
class Solution {
public:
    //root->val应该在(lower, upper)内，左子节点应该在(lower, root->val)内，右子节点应该在(root->val, upper)内，
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

/*
3. 中序遍历
BST的中序遍历是升序序列
时间复杂度 : O(n)，其中 n 为二叉树的节点个数。
空间复杂度 : O(n)，高度等于节点数
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            //这里必须向右推，无论右子节点是否为空，否则又会回到当前节点
            //就算推了空节点，这个循环不会触发while (root != nullptr)，所以不会有任何节点进栈，然后会获取栈顶，回到上一层 
            root = root -> right;
        }
        return true;
    }
};


