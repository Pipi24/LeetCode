/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 **/

//遍历到3，将3移到前面，遍历到4，将4移到前面
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr)
            return nullptr;
        //声明头节点保存第一个节点
        ListNode* headNode = new ListNode(0);
        headNode->next = head;
        //声明当前节点的前一个节点用于指向新的next
        ListNode* preNode = headNode;
        for(int i=0; i<m-1; ++i)
            preNode = preNode->next;
        ListNode* curNode = preNode->next;
        ListNode*  afterNode  = curNode->next;
        for(int i=0; i<n-m; ++i){
            //这里的curNode一直指向第一个需要反转的元素(2)
            curNode->next = afterNode->next;
            //注意下面两行区别，较下一行只有第一次时和较上一行等价
            afterNode->next = preNode->next;
            //afterNode->next = curNode;
            preNode->next = afterNode;
            afterNode=curNode->next;
        }
        return headNode->next;
    }
};