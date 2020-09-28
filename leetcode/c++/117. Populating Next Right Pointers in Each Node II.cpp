/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    queue<Node*> que;
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
            
        que.push(root);

        Node* cur = nullptr;
        int q_size = 0;
        while(!que.empty()){
            q_size = que.size();
            for(int i=0; i<q_size;++i){
                cur = que.front();
                que.pop();
                if(i!=q_size-1)
                    cur->next = que.front();
                else 
                    cur->next = nullptr;
                if(cur->left!=nullptr) que.push(cur->left);
                if(cur->right!=nullptr) que.push(cur->right);
            }
        }
        return root;
    }
};



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void helper(Node* &lastNode, Node* &cur, Node* &nextStart){
        //上一个节点不为空，说明这是当前层的第2~n个节点了,需要跟lastNode连接起来
        if(lastNode!=nullptr)
            lastNode->next = cur;
        //下一层的第一个节点
        if(nextStart==nullptr)
            nextStart = cur;
        lastNode = cur;
    }
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;

        Node* curStart = root;
        while(curStart!=nullptr){
            Node* lastNode = nullptr, *nextStart=nullptr;
            for(Node* cur= curStart; cur!=nullptr; cur=cur->next){
                //当前层构造下一层的next
                if(cur->left!=nullptr)
                    helper(lastNode, cur->left, nextStart);
                if(cur->right!=nullptr)
                    helper(lastNode, cur->right, nextStart);
            }
            curStart = nextStart;
        }

        return root;
    }
};