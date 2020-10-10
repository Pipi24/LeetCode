/*最容易想到的方法是遍历所有节点，每次遍历到一个节点时，判断该节点此前是否被访问过。

具体地，我们可以使用哈希表来存储所有已经访问过的节点。每次我们到达一个节点，如果该节点已经存在于哈希表中，则说明该链表是环形链表，否则就将该节点加入哈希表中。重复这一过程，直到我们遍历完整个链表即可。
TC：O(N)
SC：O(N)

*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

/*
如果链表中有环，那么快慢指针就一定可以相遇（且一定再环上，如图上的c点），此时快指针移动过的距离是慢指针的2倍，根据图中的参数，我们可以写出以下等式：

(m+y)*2=m+xn+y //这里的xn是当相遇时快指针已经在环上循环了x次，x>=1且为整数
=> m+y=xn => m=n-y+(x-1)*n //下面解释为什么写成这种形式

接下来将快指针置于表头(此时快指针在a处，慢指针在c处)，与慢指针以相同速度在链表上移动，当快指针移动到b处时，移动了m的距离，根据上面的等式可知，慢指针移动了n-y+(x-1)*n的距离。

我们来分析一下此时的慢指针在什么位置：
先移动(x-1)*n的距离，相当于在环上循环了(x-1)次，慢指针又回到了c点，然后再移动n-y的距离，如图所示，n-y正好是c点到b点的距离，说明此时慢指针也移动到了b点，即快慢指针在环路的开头节点相遇了。

https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/kuai-man-zhi-zhen-zheng-ming-bi-jiao-yan-jin-by-ch/

*/
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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
        {
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                break;
            }
        }
        if(fast!=slow)
        {
            return NULL;
        }
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};