/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //递归，每次找到第一个节点和最后一个节点
class Solution {
public:
    ListNode* tailNode = nullptr;
    void reorderList(ListNode* head) {
        if(head==nullptr)
            return;
        ListNode* firstNode = head;
        ListNode* lastNode = head;
        while(lastNode->next != tailNode)
            lastNode = lastNode->next;
        if(firstNode == lastNode){
            //最后一个节点的next为null
            firstNode->next = nullptr;
            return;
        }
        ListNode* afterNode = firstNode->next;
        lastNode->next = afterNode;
        firstNode->next = lastNode;
        tailNode = lastNode;
        reorderList(afterNode);
    }
};

 //先找到链表中点，把1->2->3->4变成1->2->4->3
 //再从两个head一一拼接
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr)
            return;
        //找到中间的节点
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        while(fastNode!=nullptr && fastNode->next!=nullptr){
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        ListNode* head2 = reverse(slowNode->next);
        slowNode->next = nullptr;
        while(head!=nullptr && head2!=nullptr){
            ListNode* after = head->next;
            ListNode* after2 = head2->next;
            head->next = head2;
            head2->next = after;
            head = after;
            head2 = after2;
        }
    }
    ListNode* reverse(ListNode* head){
        ListNode* preNode = nullptr;
        ListNode* curNode = head;
        while(curNode!=nullptr){
            ListNode* afterNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = afterNode;
        }
        return preNode;
    }
};

//线性表
//用数组存储节点指针
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
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};
