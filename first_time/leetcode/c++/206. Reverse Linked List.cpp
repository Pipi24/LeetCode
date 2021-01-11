/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //用stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        stack<ListNode*> s;
        while(head!=nullptr){
            s.push(head);
            head = head->next;
        }
        ListNode* ans = s.top();
        while(!s.empty()){
            ListNode* temp  = s.top();
            s.pop();
            if(!s.empty())
                temp->next = s.top();
            else
                temp->next = nullptr;
        }
        return ans;
    }
};

//之前，当前，之后三节点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* beforeNode = nullptr;
        ListNode* curNode = head;
        ListNode* afterNode = curNode->next;
        while(curNode!=nullptr){
            curNode->next = beforeNode;
            beforeNode = curNode;
            curNode = afterNode;
            if(afterNode!=nullptr)
                afterNode=afterNode->next;
        }
        return beforeNode;
    }
};
//递归，当前节点和之前节点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return help(head, nullptr);
    }
    ListNode* help(ListNode* curNode, ListNode* beforeNode){
        if(curNode==nullptr)
            return beforeNode;
        ListNode* afterNode = curNode->next;
        curNode->next  = beforeNode;
        return help(afterNode, curNode);
    }
};