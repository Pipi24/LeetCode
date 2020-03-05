/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(0);
        ListNode* largeHead = new ListNode(0);
        ListNode* small = smallHead;
        ListNode* large = largeHead;
        while(head!=nullptr){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }
            else{
                large->next = head;
                large = large->next;
            }
            head=head->next;
        }
        small->next = largeHead->next;
        large->next = nullptr;
        return smallHead->next;
    }
};