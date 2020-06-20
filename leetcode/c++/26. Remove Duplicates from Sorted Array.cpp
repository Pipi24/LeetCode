/*
解题思路：
解法： 双指针

首先注意数组是有序的，那么重复的元素一定会相邻。

要求删除重复元素，实际上就是将不重复的元素移到数组的左侧。

考虑用 2 个指针，一个在前记作 p，一个在后记作 q，算法流程如下：

1.比较 p 和 q 位置的元素是否相等。

如果相等，q 后移 1 位
如果不相等，将 q 位置的元素复制到 p+1 位置上，p 后移一位，q 后移 1 位
重复上述过程，直到 q 等于数组长度。

返回 p + 1，即为新数组长度。

画个图理解一下
时间复杂度：O(n)。
空间复杂度：O(1)。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i = 0;
        for(int j=1; j<nums.size(); ++j){
            if(nums[i]!=nums[j])
                nums[++i] = nums[j];
        }
        return i+1;           
    }
};

/*
数组中没有重复元素，按照上面的方法，每次比较时 nums[p] 都不等于 nums[q]，因此就会将 q 指向的元素原地复制一遍，这个操作其实是不必要的。

因此我们可以添加一个小判断，当 q - p > 1 时，才进行复制。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i = 0;
        for(int j=1; j<nums.size(); ++j){
            if(nums[i]!=nums[j]){
                if(j-i>1)
                    nums[++i] = nums[j];
                else
                    ++i;
            }
        }
        return i+1;           
    }
};