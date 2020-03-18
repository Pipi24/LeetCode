/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //归并
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* preSlow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        preSlow->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(0);
        ListNode* traversal = head;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val > l2->val){
                traversal->next = l2;
                l2 = l2->next;
            }else{
                traversal->next = l1;
                l1 = l1->next;
            }
            traversal = traversal->next;
        }
        if(l1!=nullptr)
            traversal->next = l1;
        if(l2!=nullptr)
            traversal->next = l2;
        return head->next;
    }
};