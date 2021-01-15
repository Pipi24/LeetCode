/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
关键：发现重复时不要马上移动pos指针，而是要找到下一个不重复的才移动pos指针
时间复杂度：O(n)，因为列表中的每个结点都检查一次以确定它是否重复，所以总运行时间为 O(n)，其中 n 是列表中的结点数。

空间复杂度：O(1)，没有使用额外的空间。


*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* pos = head;
        while(pos->next){
            if(pos->val==pos->next->val){
                ListNode* del = pos->next;
                pos->next = pos->next->next;
                delete del;
            }
            else{
                pos = pos->next;
            }
        }
        return head;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* pos = head;
        while(pos){
            while(pos->next && pos->val==pos->next->val){
                ListNode* del = pos->next;
                pos->next = pos->next->next;
                delete del;
            }
            pos = pos->next;
        }
        return head;
    }
};