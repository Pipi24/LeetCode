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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        if(head->next==nullptr)
            return head;
        //第二个节点必是返回的第一个节点
        ListNode* resNode = head->next;

        ListNode* preNode = new ListNode(0);
        ListNode* curNode = head;
        ListNode* afterNode = head->next;
        while(curNode!=nullptr && afterNode!=nullptr){
            curNode->next = afterNode->next;
            afterNode->next  = curNode;
            preNode->next = afterNode;
            preNode = afterNode->next;
            curNode = curNode->next;
            if(curNode!=nullptr)//节点个数为奇数
                afterNode = curNode->next;
            else//节点个数为偶数
                afterNode = nullptr;
        }
        return resNode;
    }
};