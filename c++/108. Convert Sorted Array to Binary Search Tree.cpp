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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        return inorder(nums, 0, nums.size()-1);
    }
    TreeNode* inorder(vector<int>& nums, int low, int high){
        if(low > high)
            return nullptr;
        int mid = (low+high+1)/2;//int mid = (low+high)/2; 也可

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = inorder(nums, low, mid-1);
        node->right = inorder(nums, mid+1, high);
        return node;
    }
};