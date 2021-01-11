这道题在原书上绝对不是简单级别啊！
它考察的是程序员的沟通能力，先问面试官要时间/空间需求！！！
只是时间优先就用字典，
还有空间要求，就用指针+原地排序数组，
如果面试官要求空间O(1)并且不能修改原数组，还得写成二分法！！！

方法1
先排序，找相邻位置相等
时间复杂度：O(nlogn)
空间复杂度：O(1)

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1;++i){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return -1;
    }
};

方法2
字典保存已出现的数字，遍历nums查询字典中该数字是否已经出现
时间复杂度：O(n)
空间复杂度：O(n)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num : nums){
            if(map[num])
                return num;
            map[num]=1;
        }
        return -1;
    }
};

方法3
就地排序，题目说到数字全在[0,n-1]区间，说明如果没有重复，数组排序后nums[i]=i，将nums[i]交换放到i位置上，如果i位置上的值已经等于nuns[i]说明发生重复
时间复杂度：O(n)
空间复杂度：O(1)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            //这里得用while而不是if，因为交换一次之后不能直接往后遍历，而是应该继续判断交换后的当前i位置的数字是否满足条件（交换后i位置的值变了）
            while(nums[i] != i)     //当前元素不等于下标
            {
                if(nums[i] == nums[nums[i]])    return nums[i];
                swap(nums[i],nums[nums[i]]);            
            }
        }   
        return -1;
    }
};

方法4 二分查找 对0到n-1进行二分查找，时间O(nlogn)，空间O(1)，不修改原数据，用时间换空间
该方法需要数字一定有重复的才行，因此如果题目修改在长度为n，数字在1到n-1的情况下，此时数组中至少有一个数字是重复的，该方法可以通过。
class Solution {
public:
    //统计nums中元素>=min, <=max的数量，如果数量大于这个值，那么重复的元素肯定是位于min到max的
    int getCount(vector<int>& nums, int min, int max){
        int count=0;
        for(int num: nums){
            if(num>=min && num<=max)
                count++;
        }
        return count;
    }
    int findRepeatNumber(vector<int>& nums) {
        int min = 1;
        int max = nums.size()-1;
        while(min<max){
            int mid = min+(max-min)/2;
            int count = getCount(nums, min, mid);
            if(count==mid-min+1)
                min = mid+1;
            else
                max = mid;
        }
        return min;
    }
};