class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> stak1; //push栈实现队列push操作
    stack<int> stak2; //pop栈实现队列pop操作
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        //直接将元素push进push栈stak1
        stak1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        //将stak1所有元素push进stak2,则stak2栈顶元素为队头元素
        while(!stak1.empty())
        {
            stak2.push(stak1.top());
            stak1.pop();
        }

        //取队头元素，并将队头元素pop
        int s = stak2.top();
        stak2.pop();

        //将stak2中元素重新放回stak1中
        while(!stak2.empty())
        {
            stak1.push(stak2.top());
            stak2.pop();
        }
        return s;
    }

    /** Get the front element. */
    int peek()
    {
        while(!stak1.empty())
        {
            stak2.push(stak1.top());
            stak1.pop();
        }
        int s = stak2.top();

        while(!stak2.empty())
        {
            stak1.push(stak2.top());
            stak2.pop();
        }
        return s;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stak1.empty() && stak2.empty();
    }
};

/*
pop 复杂度分析

时间复杂度： 摊还复杂度 O(1)，最坏情况下的时间复杂度 O(n)
在最坏情况下，s2 为空，算法需要从 s1 中弹出 n 个元素，然后再把这 n 个元素压入 s2，在这里n代表队列的大小。这个过程产生了 2n 步操作，时间复杂度为 O(n)。
但当 s2 非空时，算法就只有 O(1) 的时间复杂度。所以为什么叫做摊还复杂度 O(1) 呢？ 读了下一章你就知道了。
空间复杂度 ：O(1)

摊还分析

摊还分析给出了所有操作的平均性能。摊还分析的核心在于，最坏情况下的操作一旦发生了一次，那么在未来很长一段时间都不会再次发生，这样就会均摊每次操作的代价。
单次 出队 操作最坏情况下的时间复杂度为 O(n)。考虑到我们要做 n 次出队操作，如果我们用最坏情况下的时间复杂度来计算的话，那么所有操作的时间复杂度为 O(n^2)

然而，在一系列的操作中，最坏情况不可能每次都发生，可能一些操作代价很小，另一些代价很高。因此，如果用传统的最坏情况分析，那么给出的时间复杂度是远远大于实际的复杂度的。
例如，在一个动态数组里面只有一些插入操作需要花费线性的时间，而其余的一些插入操作只需花费常量的时间。

在上面的例子中，出队 操作最多可以执行的次数跟它之前执行过 入队 操作的次数有关。虽然一次 出队 操作代价可能很大，但是每 n 次 入队 才能产生这么一次代价为 n 的 出队 操作。
因此所有操作的总时间复杂度为：n(所有的入队操作产生） + 2 * n(第一次出队操作产生） + n - 1(剩下的出队操作产生）， 所以实际时间复杂度为 O(2∗n)。
于是我们可以得到每次操作的平均时间复杂度为 O(2n/2n)=O(1)

方法二其实不用计算分摊时间复杂度，直接考虑每个元素即可，无论是哪个元素，都是入栈两次(进一次A和一次B)，出栈两次(同理)，所以平均复杂度都是O（1)
*/



class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> stak1; //push栈实现队列push操作
    stack<int> stak2; //pop栈实现队列pop操作
    int front = 0;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        if(stak1.empty())
            front = x;
        //直接将元素push进push栈stak1
        stak1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if(stak2.empty()){
            while(!stak1.empty()){
                stak2.push(stak1.top());
                stak1.pop();
            }
        }
        //取队头元素，并将队头元素pop
        int s = stak2.top();
        stak2.pop();
        return s;
    }

    /** Get the front element. */
    int peek()
    {
        if(!stak2.empty())
            return stak2.top();
        return front;

    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stak1.empty() && stak2.empty();
    }
};



class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};