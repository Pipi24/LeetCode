/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
深拷贝指的是新建节点

解法1： hash
key是旧的节点，value是新的节点，每次操作value都要靠旧节点
时间复杂度：O(N)
空间复杂度：O(N)

*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        mp[nullptr]=nullptr;
        auto p=head;
        while(p){
            mp[p]=new Node(p->val);
            p=p->next;
        }
        p=head;
        while(p){
            mp[p]->next=mp[p->next];
            p=p->next;
        }
        p=head;
        while(p){
            mp[p]->random=mp[p->random];
            p=p->next;
        }
        return mp[head];
    }
};

/*
深拷贝指的是新建节点

解法2： 将复制节点添加到原节点后面

时间复杂度：O(N)
空间复杂度：O(1)

*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *node = head;
        //1. 将复制节点添加到原节点后面
        // 1->2->3  ==>  1->1'->2->2'->3->3'
        while (node != nullptr) {
            Node *copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        //2. 复制random节点
        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }            
            node = node->next->next;
        }
        
        //3. 分离链表
        node = head;
        Node *newHead = head->next;
        Node *tmp = nullptr;
        while (node != nullptr && node->next!=nullptr) {
            tmp = node->next;
            node->next = node->next->next;  
            node = tmp;   
        }
        // 原始链表头：head 1->2->3
        // 新的链表头：newHead 1'->2'->3'
        return newHead;
    }
};
