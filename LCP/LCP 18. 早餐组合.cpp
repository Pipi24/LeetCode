class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(drinks.begin(), drinks.end());
        int ans=0;
        int mod=1e9+7;
        int m = staple.size(), n = drinks.size();
        for(int i=0; i<m; ++i){
            int target = x-staple[i];
            if(target<=0)
                continue;
            int low=0, high=n;
            while(low<high){
                int mid = low + (high-low)/2;
                //寻找右边界
                if(drinks[mid]>target)
                    high=mid;
                else
                    low=mid+1;
            }
            ans+=low;
            ans%=mod;
        }
        return ans;
    }
};

二分查找有几种写法？它们的区别是什么？ - labuladong的回答 - 知乎
https://www.zhihu.com/question/36132386/answer/712269942