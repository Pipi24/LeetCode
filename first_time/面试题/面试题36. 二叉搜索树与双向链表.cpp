/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
/*
1. 将左子树全部压入一个栈
2. 每次pop出一个节点，将该节点的右子树的左子树全部压栈
3. 定义before，after两个节点进行连接操作，注意第一个和最后一个节点的处理
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)
            return nullptr;
        stack<Node* > s;

        Node*  before = nullptr;
        Node* cur = root;
        Node* after = nullptr;
        //需要单独定义一个head，保存最终链表的起始位置，就是左子树的最左孩子
        Node* head = nullptr;

        while(cur!=nullptr){
            s.push(cur);
            //head指向最左孩子
            head = cur;
            cur = cur->left;
        }

        while(!s.empty()){
            cur = s.top();
            s.pop();
            Node* tmp = cur->right;
     
            while(tmp!=nullptr){
                s.push(tmp);
                tmp = tmp->left;
            }

            if(s.empty())
                //最后一个节点的right是head
                after = head;
            else
                after = s.top();
            cur->left = before;
            cur->right = after;
            
            before = cur;
        }
        //第一个节点的left是最后一个节点
        head->left = before;
        return head;
    }
};