class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        vector<vector<int>> opt(len, vector<int>(2,0));
        opt[0][0] = 0;
        opt[0][1] = -prices[0];
        for(int i = 1; i < len; ++i){
            opt[i][0] = max(opt[i-1][0], opt[i-1][1] + prices[i]);
            opt[i][1] = max(opt[i-1][1], -prices[i]);
        }
        return opt[len-1][0];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        int opt_i_0 = 0;
        int opt_i_1 = -prices[0];
        for(int i = 1; i < len; ++i){
            opt_i_0 = max(opt_i_0, opt_i_1 + prices[i]);
            opt_i_1 = max(opt_i_1, -prices[i]);
        }
        return opt_i_0;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 1; i < len; ++i){
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i]-min_price);
        }
        return max_profit;
    }
};