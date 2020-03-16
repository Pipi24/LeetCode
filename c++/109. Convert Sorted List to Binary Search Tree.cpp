/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        if(head->next==nullptr)
            return new TreeNode(head->val);
        ListNode* preSlow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        preSlow->next=nullptr;

        TreeNode* root = new TreeNode(slow->val);
        ListNode* leftHead = head;
        ListNode* rightHead = slow->next;

        root->left = sortedListToBST(leftHead);
        root->right = sortedListToBST(rightHead);
        return root;
    }
};