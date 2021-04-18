class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                result = result > dp[i][j]? result: dp[i][j];
            }
        }
        return result;
    }
};


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= m; ++i){
            for(int j = n; j >= 1; --j){
                if(nums1[i - 1] == nums2[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else
                    dp[j] = 0; // 注意这里不相等的时候要有赋0的操作 
                result = result > dp[j]? result: dp[j];
            }
        }
        return result;
    }
};