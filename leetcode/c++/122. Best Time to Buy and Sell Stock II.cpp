class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
		//第一天未持有，dp=0
		//第一题持有，说明买了第一天的，dp=-prices[0];
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for(int i = 0; i<len; ++i){
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, tmp - prices[i]);
        }
        return dp_i_0;
    }
};


//六个股票问题通用框架
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;
        for(int i = 1; i<len; ++i){
            if(prices[i]>prices[i-1])
                profit += prices[i]-prices[i-1];
        }
        return profit;
    }
};