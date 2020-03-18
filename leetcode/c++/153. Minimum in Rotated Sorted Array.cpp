class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int m=s;
        while(nums[s]>nums[e]){
            if(e-s==1){
                m=e;
                break;
            }
            m = (s+e)/2;
            if(nums[m]>nums[s])
                s=m;
            else if(nums[m]<nums[e])
                e=m;
        }
        return nums[m];
    }
};