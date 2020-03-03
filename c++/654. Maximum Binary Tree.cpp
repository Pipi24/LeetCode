/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归 类比有序数组构造BST
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        return help(nums, 0, nums.size()-1);
    }
    TreeNode* help(vector<int>& nums, int start, int end){
        if(start>end)
            return nullptr;
        int max_num = INT_MIN;
        int max_idx = 0;
        for(int i=start; i<=end; ++i){
            if(nums[i]>max_num){
                max_num=nums[i];
                max_idx = i;
            }
        }
        TreeNode* root = new TreeNode(max_num);
        root->left = help(nums, start, max_idx-1);
        root->right = help(nums, max_idx+1, end);
        return root;
    }
};


 /**
 /*迭代思路：从左到右遍历数组，在deque(stack)找到当前数字的合适位置，比它小的放在它的左子树，比它大的将它放到大节点的右子树
 /*若当前元素最大，将其作为栈底
 **/
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        //双向队列，用它不用栈的目的是最后要取stack的底部元素，理解是当作栈
        deque<TreeNode*> d;
        //从左到右遍历数组
        for(int i=0; i<nums.size(); ++i){
            TreeNode* node = new TreeNode(nums[i]);
            //如果当前nums[i]比栈顶元素大，说明栈顶元素应在当前节点的左边，弹出栈顶元素
            //直到找到比栈顶元素小的位置或者栈空（此时nums[i]是最大元素），位于栈底
            while(!d.empty() && nums[i]>d.back()->val){
                node->left = d.back();
                d.pop_back();
            }
            //如果当前nums[i]不是最大的，那么它应该在栈顶元素的右边
            if(!d.empty()){
                d.back()->right = node; 
            }
            d.push_back(node);
        }
        return d.front();
    }
};