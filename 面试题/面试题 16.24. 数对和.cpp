/*
利用unordered_map存储每个数组元素i出现的次数，
若target-i出现过，就一起放入返回容器中，并将target-i出现的次数减1
否则将i出现的次数加1

*/
/hash
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<vector<int>>res;
        for(auto i : nums){
            if(m[target-i]>0){
                m[target-i]--;
               res.push_back({target-i,i}); 
            }
            else m[i]++;
        }
        return res;
    }
};

//双指针
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) res.push_back({nums[i ++], nums[j --]});
            else if (sum < target) i ++;
            else j --;
        }
        return res;
    }
};
