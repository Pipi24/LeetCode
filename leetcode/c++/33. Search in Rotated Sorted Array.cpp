/* 根据中点将数组分为两段，其中至少一段有序，根据target是否在该有序区间内决定舍弃哪一段 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size())
            return -1;
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
                return mid;
            //左边有序
            if(nums[left]<=nums[mid]){
                //且在[left,mid)范围内
                if(target>=nums[left] && target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
            //右边有序，不排除两边都有序
            else{
                if(target>nums[mid] && target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};