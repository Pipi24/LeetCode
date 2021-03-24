/*
时间复杂度：O(n)，
假设数组总共有 n 个元素，i 和 j 至少遍历 2n 步。

空间复杂度：O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for(int fast=0; fast< nums.size(); fast++){
            if(nums[fast]!=val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

/*
时间复杂度：O(n)，i 和 n 最多遍历 n 步。在这个方法中，赋值操作的次数等于要删除的元素的数量。因此，如果要移除的元素很少，效率会更高。

空间复杂度：O(1)。

*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size()-1;
        while(i <= n){
            if(nums[i]==val){
                nums[i] = nums[n];
                n--;
            }else{
                i++;
            }
        }
        /* i==n时, 
        若nums[i]==val,此时n--,i指向第一个val出现的下标, 即长度
        若nums[i]!=val,此时i++,i指向第一个val出现的下标, 即长度
        */
        return i;
        // 或者 n+1;
    }
};
