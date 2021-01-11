//双指针 一次遍历
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);  //哑节点
        if(!head)  return head;
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for(int i=0; i<n;i++)
        {
        q=q->next;
        }
        while(q->next)
        {
           p= p->next;
           q= q->next;
        }
        p->next = p->next->next;  //删除p->next的节点
   
        ListNode* res = dummy->next;
        delete dummy;   //删除哑节点
        return res;

    }
};

//2次遍历
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        if(n==len) return head->next;  //如果是第一个，则直接返回head->next;
        int m=len-n-1;                 //倒数第n个，就是从头开始第len-n+1个，但是我们要保存他的前一个数字，并且数字是从1开始的；这里减了一个2
        ListNode* pre=head,* now=head->next;
        while(m>0){
            pre=pre->next;
            now=now->next;
            m--;
        }
        pre->next=now->next;
        return head;
    }
};


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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* first = dummy;

        //要指向哑节点，好处理删除第一个节点
        ListNode* second = dummy;

        while(first){
            // first 先走n+1步, 因为最后的判断条件是first不为空,此时second才是走到了要删除节点的前面一个节点
            if(n>=0){
                first = first->next;
                n--;
            }
            else{
                first = first->next;
                second = second->next;
            }
        }
        second->next = second->next->next;
        return dummy->next;
    }
};