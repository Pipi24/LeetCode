
/*方法一：辅助栈
思路

要做出这道题目，首先要理解栈结构先进后出的性质。

对于栈来说，如果一个元素 a 在入栈时，栈里有其它的元素 b, c, d，那么无论这个栈在之后经历了什么操作，只要 a 在栈中，b, c, d 就一定在栈中，因为在 a 被弹出之前，b, c, d 不会被弹出。

因此，在操作过程中的任意一个时刻，只要栈顶的元素是 a，那么我们就可以确定栈里面现在的元素一定是 a, b, c, d。

那么，我们可以在每个元素 a 入栈时把当前栈的最小值 m 存储起来。在这之后无论何时，如果栈顶元素是 a，我们就可以直接返回存储的最小值 m。

时间复杂度：对于题目中的所有操作，时间复杂度均为 O(1)。因为栈的插入、删除与读取操作都是 O(1)，我们定义的每个操作最多调用栈操作两次。

空间复杂度：O(n)，其中 n 为总操作数。最坏情况下，我们会连续插入 nn 个元素，此时两个栈占用的空间为 O(n)。


*/
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
/*
解法2：一个栈同时保存当前值和栈内最小值

题目要求在常数时间内获得栈中的最小值，因此不能在 getMin() 的时候再去计算最小值，最好应该在 push 或者 pop 的时候就已经计算好了当前栈中的最小值。

前排的众多题解中，基本都讲了「辅助栈」的概念，这是一种常见的思路，但是有没有更容易懂的方法呢？

可以用一个栈，这个栈同时保存的是每个数字 x 进栈的时候的值 与 插入该值后的栈内最小值。即每次新元素 x 入栈的时候保存一个元组：（当前值 x，栈内最小值）。

这个元组是一个整体，同时进栈和出栈。即栈顶同时有值和栈内最小值，top()函数是获取栈顶的当前值，即栈顶元组的第一个值； getMin() 函数是获取栈内最小值，即栈顶元组的第二个值；pop() 函数时删除栈顶的元组。

每次新元素入栈时，要求新的栈内最小值：比较当前新插入元素 x 和 当前栈内最小值（即栈顶元组的第二个值）的大小。

新元素入栈：当栈为空，保存元组 (x, x)；当栈不空，保存元组 (x, min(此前栈内最小值， x)))
出栈：删除栈顶的元组。

时间复杂度：O(1)
空间复杂度：O(N)，少用了辅助站，从O(2N)变为O(N)
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (st.size() == 0) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */