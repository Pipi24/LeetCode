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
方法1：迭代/遍历

关键：

1. 指针保存的是一个地址：对于链表节点指针，该指针保存了链表节点结构体的地址，因此就算使用了->next方法，指针本身指向的地址是没有改变的
即：pos->next = pos->next->next; 这一句没有改变pos指向的地址，但pos = pos->next;这一句改变了pos指向的地址

1.1 当头节点不会被删除时，例如1->2->3->3->4，dummy->next就是要返回的节点，就等于原来的头节点

1.2 当头节点会被删除时，例如1->1->1->2->3，在下面的if代码中是通过pos->next = pos->next->next;来移动pos->next的，但并没有改变pos本身指向的地址，所以dummy->next也是随着pos->next的移动而移动的，
因为他们指向的地址是一样的，而当执行了pos = pos->next;后，他们的地址就不一样了，pos的改变将不再影响到dummy，因此返回值是dummy->next，代表了首个不重复节点，这里就不是1.1中的原来的头节点了。

2. 存在删除头节点的情况时要用哑节点指向头节点，便于操作

3. 记录重复的值而不是用指针来判断是否重复会更清晰简单

时间复杂度: O(N)，遍历了一遍节点
空间复杂度: O(1)，两个指针
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pos = dummy;

        //记录重复的值
        int del_value = 0;
        while(pos->next && pos->next->next){
            if(pos->next->val == pos->next->next->val){
                del_value = pos->next->val;
                while(pos->next && pos->next->val==del_value)
                    pos->next = pos->next->next;
            }
            else{
                pos = pos->next;
            }
                
        }
        return dummy->next;
    }
};

/*
方法2：递归
时间复杂度: O(N)，遍历了一遍节点
空间复杂度: O(N)，全部不同
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	// head为空，返回head，head->next为空，必不能重复，仍返回head
        if(!head || !head->next) return head;
        if(head->next->val != head->val)
        {
            // 如果head后面一位的元素的值不等于head的值，就从head->next开始接着处理后面的链表
            head -> next = deleteDuplicates(head -> next);
            return head;
        } 
        else
        {
            // 如果head后面一位的元素的值等于head的值，就跳过所有与head的值相等的元素，从第一个不等于head值的元素开始处理
            ListNode *curr = head;
            while(curr->next && curr->next->val==curr->val) curr = curr -> next;
            return deleteDuplicates(curr -> next);
        }
    }
};