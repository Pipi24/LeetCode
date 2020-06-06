class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};
/*
当时是做并查集这个标签的题，所以知道这题能用并查集做，但是发现别人写的并查集都贼长。
没有按秩压缩，时间效率没有迭代的高。
思路：

初始化的时候先把数组里每个元素初始化为他的下一个数；
并的时候找他能到达的最远的数字就可以了。

*/

class Solution {
public:
    unordered_map<int,int> a,b;
    int find(int x){
        return a.count(x)?a[x]=find(a[x]):x;
    }
    int longestConsecutive(vector<int>& nums) {
        for(auto i:nums)
            a[i]=i+1;
        int ans=0;
        for(auto i:nums){
            int y=find(i+1);
            ans=max(ans,y-i);
        }
        return ans;
    }
};
/*
第二种方法是迭代
用unordered_map 相当于排序，省去了排序的多余的log(n)时间复杂度；
这样排完序连续的序列只用遍历最小的就可以了；
倒着遍历是因为每次计算 size() 也会耗费一点时间，虽然很少，但是肯定没有直接用变量快吧。

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> a;
        for(auto i:nums)
            a[i]=i;
        int ans=0;
        for(int i=nums.size()-1;i>=0;--i){
            if(!a.count(nums[i]-1)){
                int cur=nums[i];
                while(a.count(cur+1)){
                    ++cur;
                }
                ans=max(ans,cur-nums[i]+1);
            }
        }
        return ans;
    }
};
