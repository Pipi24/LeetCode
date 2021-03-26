/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*1. 迭代：
关键：保存当前节点的前继节点和后继节点，后继要先保存，因为会修改
时间复杂度: O(N)，遍历了一遍节点
空间复杂度: O(1)，两个指针
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* pre=nullptr;
        ListNode* back=nullptr;
        while(head){
            //先保存next节点
            back = head->next;
            head->next = pre;
            //先后挪一位
            pre = head;
            head = back;
        }
        return pre;
    }
};

/*2. 递归

关键：当我们处于nk，假设nk+1节点后面的已被反转，如n1->n2->...->nk->nk+1<-...<-nm，此时需要将nk+1 ->next指向nk，所以有head->next->next = head;先指过去再指回来
同时还要把head->next置为nullptr，否则会在n1->next将不为nullptr，会出现环

时间复杂度：O(n)，其中 n 是链表的长度。需要对链表的每个节点进行反转操作。

空间复杂度：O(n)，其中 n 是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为 n 层。


*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

