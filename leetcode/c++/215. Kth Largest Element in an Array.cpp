class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start=0, end=nums.size()-1,index=0;
        while(start <= end){
            index = partition(nums, start, end);
            if(index == k-1)
                return nums[index];
            else if(index > k-1)
                end = index - 1;
            else
                start = index +1;
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int start, int end){
        int low = start;
        int high = end;
        int bound = nums[low];
        
        while(low<high){
            while(low<high && nums[high] <= bound)
                high--;
            nums[low] = nums[high];
            while(low<high && nums[low] >= bound)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = bound;
        return low;
    }
};