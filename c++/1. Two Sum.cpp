class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        vector<int> index;
        for(int i=0; i<nums.size(); ++i){
            if(dict.count(target - nums[i])){
                index.push_back(dict[target-nums[i]]);
                index.push_back(i);
                return index;
            }
            dict[nums[i]] = i;
        }
        return index;
    }
};