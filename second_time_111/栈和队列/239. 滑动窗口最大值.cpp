class Solution {
private:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。 
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口移除最前面元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            //头部保存最大值，若滑动窗口已经掠过了最大值的对应的下标，删除头部元素
            if(!dq.empty() && dq.front()<i-k+1)
                dq.pop_front();
            //当来一个新元素，判断他是否比尾部大，若大，删除尾部节点,相等也加进去，保证下标较大
            while(!dq.empty() && nums[i]>nums[dq.back()])
                dq.pop_back();
            //插入新元素
            dq.push_back(i);
            //判断滑动窗口是否形成，形成了，返回当前滑动窗口的最大值
            //i指向窗口的最后一个值
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};