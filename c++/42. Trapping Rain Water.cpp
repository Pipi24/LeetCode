暴力法O(N^2)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for(int i=1; i<n-1; i++){
            int leftMax=0, rightMax=0;
            for(int j=i; j>=0; j--)
                leftMax=max(leftMax, height[j]);
            for(int j=i; j<=n-1; j++)
                rightMax=max(rightMax, height[j]);
            ans+=min(leftMax, rightMax)-height[i];
        }
        return ans;
    }
};

增加两个数组改进暴力法O(N),空间复杂度O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(n==0)
            return ans;
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        for(int i=1; i<n; i++)
            leftMax[i]=max(height[i],leftMax[i-1]);
        for(int i=n-2; i>=0; i--)
            rightMax[i]=max(height[i],rightMax[i+1]);
        for(int i=1; i<n-1; i++) //0和n-1位置的雨水必定为0
            ans+=min(leftMax[i], rightMax[i])-height[i];
        return ans;
    }
};

双指针法O(N),空间复杂度O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(n==0)
            return ans;
        int leftMax=0, rightMax=0;
        //双指针
        int left=0, right=n-1; 
        //可以相等是因为相等时遍历到最后一个位置，是需要进行循环内的计算的
        while(left<=right){
            leftMax=max(leftMax,height[left]);
            rightMax=max(rightMax,height[right]);
            if(leftMax<rightMax){
                //leftMax<rightMax,说明当前left位置的雨水受leftMax的制约
                ans+=leftMax-height[left];
                //这是left位置能接的雨水已经算出,所以left++;
                left++;
            }
            else{
                ans+=rightMax-height[right];
                right--;
            }
        }
        return ans;
    }
};