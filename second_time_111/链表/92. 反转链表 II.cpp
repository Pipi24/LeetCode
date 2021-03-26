/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 思路：先遍历到m处，翻转，再拼接后续，注意指针处理
 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 时间复杂度：O(N)
 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;

        // 最开始：1->2->3->4->5->nil

        int i=0;
        //保存两个拼接位置：1、2
        ListNode* cat1 = nullptr;
        ListNode* cat2 = nullptr;
        while(i<m){
            cat1 = cur;
            cur = cur->next;
            ++i;
        }
        //遍历之后： 1(cat1)->2(cur)->3->4->5->NUL
        //开始反转
        cat2 = cur;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(cur && i<=n){
            //1 null<-2 3->4->5->null
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            ++i;
        }
        // 循环结束：1(cat1) null<-2(cat2)<-3<-4(pre) 5(cur)->null
        cat1->next = pre;
        cat2->next = cur;
        return dummy->next;

    }
};