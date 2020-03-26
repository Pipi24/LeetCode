class MaxQueue {
public:
    queue<int> q;
    deque<int> maxQueue;
    
    MaxQueue() {
    }
    
    int max_value() {
        if(maxQueue.empty())
            return -1;
        return maxQueue.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!maxQueue.empty() && value > maxQueue.back())
            maxQueue.pop_back();
        maxQueue.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        //int tmp  = q.pop();
        int tmp = q.front();
        q.pop();
        if(tmp ==  maxQueue.front())
            maxQueue.pop_front();
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */