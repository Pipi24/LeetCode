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