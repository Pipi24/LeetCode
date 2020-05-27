//https://leetcode-cn.com/problems/3sum/solution/man-hua-jue-bu-wu-ren-zi-di-xiang-kuai-su-kan-dong/
class Solution {
public
    vectorvectorint threeSum(vectorint& nums) {
        vectorvectorint res;
        vectorint tmp;
        int len = nums.size(), left, right, sum;
        if(len  3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i  len; i++)
        {
            if(nums[i]  0) break;
            if(i0 && nums[i] == nums[i-1]) continue;
            left = i+1, right = len - 1;
            while(left  right)
            {   
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {   
                    tmp = {nums[i], nums[left], nums[right]};
                    res.emplace_back(tmp);
                    while(left  right && nums[left] == nums[left+1]) left++;
                    while(left  right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum  0) right--;
                else left++;
            }
        }
        return res;

    }
};



vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>num;
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size();i++){
            if (M.find(nums[i]) == M.end())
            {
                M[nums[i]] = 1;//新出现的数字
                num.push_back(nums[i]);//不存在重复数字的数组
            }
            else
                M[nums[i]]++;//记录某个数字出现的次数
        }
        sort(num.begin(), num.end());
        //int firstoutput = 1;
        for (int i = 0; i < num.size(); i++)
        {
			//因为预处理成没有重复的数组，所以j要从i开始遍历，如-1，-1，2这样的情况
            for (int j = i; j < num.size();j++){
                if(j==i&&M[num[j]]==1)//下标相同，即元素相同，但是却只出现了一次，就应该跳过，不存在-1，-1，2，让j指向下一个元素
                    continue;
                if(-num[i]-num[j]<num[j])//三数之和小于零-2，-1，-1
                    continue;
                if (M.find(-num[i] - num[j]) != M.end())//和等于0
                {
                    if (-num[i] - num[j]==num[j]){//如果与num[i] + num[j]相加等于0的数是num[j]，则num[j]至少出现两次，多的可以三次
                        if(num[j]==num[i]){
                            if(M[num[j]]<=2)continue;//如果三数相等，只能是0，0，0
                        }
                        else{
                            if(M[num[j]]==1)continue;//-2，1，1，但1其实只出现了1词的话就不行
                        }
                    }
                    result.push_back(vector<int>{num[i],num[j],-num[i] - num[j]});
                }
            }
        }
        return result;
    }

作者：rt-huang
链接：https://leetcode-cn.com/problems/3sum/solution/shuang-zhi-zhen-fa-hashfa-c-by-rt-huang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。