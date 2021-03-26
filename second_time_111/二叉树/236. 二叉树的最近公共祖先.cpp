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
1. 递归
关键： 当q或p是当前节点时，最近公共祖先就是自己或者自己的父节点，向上返回
时间复杂度：O(N)，每个节点访问一次
空间复杂度：O(N)，最坏情况高度等于节点数
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        // 当q或p是当前节点时，最近公共祖先就是自己或者自己的父节点
        if(q==root || p==root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //左右子节点各能找到p或q，说明p,q分别在当前节点的两边
        if(left!=nullptr && right!=nullptr)
            return root;
        //左子节点能找到p和q
        if(left!=nullptr)
            return left;
        //右子节点能找到p和q
        if(right!=nullptr)
            return right;
        //找不到p, q
        return nullptr;
    }
};


/*
1. 存储父节点
用哈希表存储所有节点的父节点，然后可以利用节点的父节点信息从 p 结点开始不断往上跳，并记录已经访问过的节点，再从 q 节点开始不断往上跳，如果碰到已经访问过的节点，那么这个节点就是我们要找的最近公共祖先。

时间复杂度：O(N)，二叉树的所有节点有且只会被访问一次，从 p 和 q 节点往上跳经过的祖先节点个数不会超过 N
空间复杂度：O(N)，存储每个节点的父节点
*/
class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};
