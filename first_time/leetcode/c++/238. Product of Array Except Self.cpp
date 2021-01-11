/*
方法一
左右两边的乘积再相乘
时间复杂度O(N)
空间复杂度O(N)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();

        // L 和 R 分别表示左右两侧的乘积列表
        vector<int> L(length, 0), R(length, 0);

        vector<int> answer(length);

        // L[i] 为索引 i 左侧所有元素的乘积
        // 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
        L[0] = 1;
        for (int i = 1; i < length; i++) {
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] 为索引 i 右侧所有元素的乘积
        // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            R[i] = nums[i + 1] * R[i + 1];
        }

        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < length; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};

/*
方法二
由于输出数组不算在空间复杂度内，那么我们可以将 L 或 R 数组用输出数组来计算。先把输出数组当作 L 数组来计算，然后再动态构造 R 数组得到结果。让我们来看看基于这个思想的算法。

算法

初始化 answer 数组，对于给定索引 i，answer[i] 代表的是 i 左侧所有数字的乘积。
构造方式与之前相同，只是我们试图节省空间，先把 answer 作为方法一的 L 数组。
这种方法的唯一变化就是我们没有构造 R 数组。而是用一个遍历来跟踪右边元素的乘积。
并更新数组 answer[i]=answer[i]*R 。然后 R 更新为 R=R*nums[i]，其中变量 R 表示的就是索引右侧数字的乘积。
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};

/*
方法三
解题思路 同时算两边
每个索引被遍历两次，一次放了该索引左边的乘积，另一次放了右边
left和right两个变量分别表示当前索引左边和右边的乘积
简单易懂
eg [1,2,3,4]:
1.初始化 res = [1,1,1,1], left = 1, right = 1;
2.i = 0, j = 3 res = [1,1,1,1], left = 1, right = 4;
3.i = 1, j = 2 res = [1,1,4,1], left = 2, right = 12;
4.i = 2, j = 1 res = [1,12,8,1], left = 6, right = 24;
5.i = 3, j = 0 res = [24,12,8,6] 不重要了，输出res
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int left = 1, right = 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i ++, j --) {
            res[i] *= left; res[j] *= right;
            left *= nums[i]; right *= nums[j];
        }
        return res;
    }
};


