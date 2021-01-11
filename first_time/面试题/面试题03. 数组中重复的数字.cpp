class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            while(nums[i] != i){
                if(nums[nums[i]] == nums[i])
                    return nums[i];
                //swap nums[nuns[i]] and nums[i]
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                //注意下面的下标要写成temp而不是nums[i]
                nums[temp] = temp;
            }
        }
        return -1;
    }
};