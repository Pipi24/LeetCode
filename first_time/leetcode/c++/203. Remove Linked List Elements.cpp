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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        if(head==nullptr)
            return nullptr;
        
        ListNode* temp = head;
        while(temp->next!=nullptr){
            if(temp->next->val==val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};