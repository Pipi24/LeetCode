/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
需维护两个链表 small 和 large 即可，small 链表按顺序存储所有小于 x 的节点，large 链表按顺序存储所有大于等于 x 的节点。
遍历完原链表后，只要将small 链表尾节点指向 large 链表的头节点即能完成对链表的分隔。

时间复杂度: O(n)，其中 n 是原链表的长度。我们对该链表进行了一次遍历。
空间复杂度: O(1)
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