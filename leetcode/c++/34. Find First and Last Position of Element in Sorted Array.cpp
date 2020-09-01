/* 两次二分查找
一次找等于目标值的最左下标，等于目标值的最右下标 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int left = leftIndexSearch(nums, target);
        //第一次没找到，说明不存在
        if(left==-1)
            return ans;
        int right = rightIndexSearch(nums, target);
        ans[0]=left;
        ans[1]=right;
        return ans;
    }
    int leftIndexSearch(vector<int>& nums, int target){
        int left=0, right=nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else{
                //当前索引为左边第一个target值候选
                ans=mid;
                //再从当前索引的左边继续找
                right=mid-1;
            }
        }
        return ans;
    }
    
    int rightIndexSearch(vector<int>& nums,  int target){
        int left=0, right=nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else{
                ans=mid;
                left=mid+1;
            }
        }
        return ans;
    }

};
/* 
两次查找
但使用同一个索引寻找函数，逻辑是寻找第一个大于等于目标值的下标，注意这个目标值可能不存在 */

class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        
        int left = indexSearch(nums, target);
        //第一个条件是判断是否到达数组右端，会产生越界访问，这说明target不存在
        //第二个条件是判断返回的left对应的值是否与target相等，不等的话说明target不存在
        if(left==nums.size() || nums[left]!=target)
            return ans;
        //第一个大于等于target+1的下标，其减1后即是target的最右下标
        int right = indexSearch(nums, target+1);
        ans[0]=left;
        ans[1]=right-1;
        return ans;
    }
    int indexSearch(vector<int>& nums, int target){
        int left=0, right=nums.size();

        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target)
                left=mid+1;
            //大于等于目标值时，取左半段
            else
                right=mid;
        }
        return left;
    }

};
