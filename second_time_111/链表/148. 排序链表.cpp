/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 1. 自顶向下归并，递归
 关键：
 1）找到中点
 2）对两边进行递归。递归的终止条件是链表的节点个数小于或等于 1，即当链表为空或者链表只包含 1 个节点时，不需要对链表进行拆分和排序。
 3）合并
时间复杂度：O(nlogn)，其中 n 是链表的长度。

空间复杂度：O(logn)，其中 n 是链表的长度。空间复杂度主要取决于递归调用的栈空间。


 */
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

 /*
 2. 自底向上归并，迭代
length，然后将链表拆分成子链表进行合并。

具体做法如下。

用 subLength 表示每次需要排序的子链表的长度，初始时 subLength=1。

每次将链表拆分成若干个长度为 subLength 的子链表（最后一个子链表的长度可以小于subLength），按照每两个子链表一组进行合并，合并后即可得到若干个长度为subLength×2 的有序子链表
（最后一个子链表的长度可以小于subLength×2）。合并两个子链表仍然使用「21. 合并两个有序链表」的做法。

将 subLength 的值加倍，重复第 2 步，对更长的有序子链表进行合并操作，直到有序子链表的长度大于或等于 \length，整个链表排序完毕。


时间复杂度：O(nlogn)，其中 n 是链表的长度。

空间复杂度：O(1)。


 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        //得到链表长度
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            //prev保存上一个subLength*2链表块的最后一个节点，用于连接后面的链表块，每次subLength更新后重新回到链表头
            //curr表示当前subLength*2链表块的第一个节点
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            //当当前subLength对于的subLength*2链表块还没遍历完时
            while (curr != nullptr) {
                //某subLength*2链表块的第一个subLength链表头
                ListNode* head1 = curr;
                //curr走到了第一个subLength链表尾
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                //某subLength*2链表块的第二个subLength链表头
                ListNode* head2 = curr->next;
                //断开第一个subLength链表的尾巴
                curr->next = nullptr;
                curr = head2;
                //最后一个子链表的长度可以小于subLength×2
                //curr走到了第二个subLength链表尾
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                //如果后面还有subLength*2链表块
                if (curr != nullptr) {
                    //保存后面的头节点
                    next = curr->next;
                    //断开第二个subLength链表的尾巴
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                //连接已经排序的subLength*2链表块
                prev->next = merged;
                //走到已经排序的subLength*2链表块的尾巴，用于连接后面的链表块
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                //当前节点指向后一个subLength*2链表块的头节点
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        int length = getLength(head);
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
       
        for(int step = 1; step < length; step*=2){ //依次将链表分成1块，2块，4块...
            //每次变换步长，pre指针和cur指针都初始化在链表头
            ListNode pre = dummy; 
            ListNode cur = dummy.next;
            while(cur!=null){
                ListNode h1 = cur; //第一部分头 （第二次循环之后，cur为剩余部分头，不断往后把链表按照步长step分成一块一块...）
                ListNode h2 = split(h1,step);  //第二部分头
                cur = split(h2,step); //剩余部分的头
                ListNode temp = merge(h1,h2); //将一二部分排序合并
                pre.next = temp; //将前面的部分与排序好的部分连接
                while(pre.next!=null){
                    pre = pre.next; //把pre指针移动到排序好的部分的末尾
                }
            }
        }
        return dummy.next;
    }
    public int getLength(ListNode head){
    //获取链表长度
        int count = 0;
        while(head!=null){
            count++;
            head=head.next;
        }
        return count;
    }
    public ListNode split(ListNode head,int step){
        //断链操作 返回第二部分链表头
        if(head==null)  return null;
        ListNode cur = head;
        for(int i=1; i<step && cur.next!=null; i++){
            cur = cur.next;
        }
        ListNode right = cur.next;
        cur.next = null; //切断连接
        return right;
    }
    public ListNode merge(ListNode h1, ListNode h2){
    //合并两个有序链表
        ListNode head = new ListNode(-1);
        ListNode p = head;
        while(h1!=null && h2!=null){
            if(h1.val < h2.val){
                p.next = h1;
                h1 = h1.next;
            }
            else{
                p.next = h2;
                h2 = h2.next;
            }
            p = p.next;           
        }
        if(h1!=null)    p.next = h1;
        if(h2!=null)    p.next = h2;

        return head.next;     
    }
}