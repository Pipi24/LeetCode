//暴力法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        for(int i=0; i<height.size(); ++i){
            for(int j=height.size()-1; j>i; --j){
                res = max(res, (j-i)*min(height[i], height[j]));
            }
        }
        return res;
    }
};

//双指针法
//证明关键：矮的移动一步消去的一排肯定不大于矮移动之前的值
//https://leetcode-cn.com/problems/container-with-most-water/solution/shuang-zhi-zhen-fa-zheng-que-xing-zheng-ming-by-r3/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i = 0;
        int j = height.size()-1;
        while(i<j){
            res = max(res, (j-i)*min(height[i], height[j]));
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return res;
    }
};