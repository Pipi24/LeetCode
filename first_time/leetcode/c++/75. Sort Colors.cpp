class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int ptr =0;
        //第一次遍历，把0全放到最前面
        for(int i=0; i<size;++i){
            if(nums[i]==0){
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        //第二次遍历，把1全放到0后面，2前面
        for(int i=ptr; i<size;++i){
            if(nums[i]==1){
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        return ;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//0 挪到最前面，2 挪到最后面就完事儿了
//注意 2 挪完如果换出来的不是 1，那么指针要回退，因为 0 和 2 都是需要再次移动的
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 2)
            return;
        // int bucket[3] = { 0 }; //计数桶
        // //计数排序
        // for (int& i : nums)
        //     ++bucket[i];
        // int j = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     if (bucket[j] > 0)    
        //     {
        //         nums[i] = j;
        //         --bucket[j];
        //     }
        //     else
        //     {
        //         ++j;
        //         --i;
        //     }
        // }
        // return;

        //双指针
        int p = 0, q = n - 1;
        for (int i = 0; i <= q; ++i)
        {
            if (nums[i] == 0)
            {
                nums[i] = nums[p];
                nums[p] = 0;
                ++p;
            }
            if (nums[i] == 2)
            {
                nums[i] = nums[q];
                nums[q] = 2;
                --q;
                if (nums[i] != 1)
                    --i;
            }
        }
        return;
    }
};