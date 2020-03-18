class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        vector<vector<vector<int>>> opt(len, vector<vector<int>>(3, vector<int>(2,0)));
        for(int k = 0; k < 3; ++k){
            opt[0][k][0] = 0;
            opt[0][k][1] = -prices[0];
        }
        for(int i = 1; i < len; ++i){
            for(int k = 2; k > 0; --k){
                opt[i][k][0] = max(opt[i-1][k][0], opt[i-1][k][1] + prices[i]);
                opt[i][k][1] = max(opt[i-1][k][1], opt[i-1][k-1][0] - prices[i]);
            }
        }
        return opt[len-1][2][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        int min_price = prices[0];
        int max_price = prices[len-1];

        vector<int> left_profit(len, 0);
        vector<int> right_profit(len, 0);

        int max_profit = 0;

        for(int i = 1; i < len; ++i){
            min_price = min(min_price, prices[i]);
            left_profit[i] = max(left_profit[i-1], prices[i]-min_price);
        }
        for(int i = len-2; i > 0; --i){
            max_price = max(max_price, prices[i]);
            right_profit[i] = max(right_profit[i+1], max_price -prices[i]);
        }
        for(int i = 0; i<len; ++i)
            max_profit = max(max_profit, left_profit[i] + right_profit[i]);
        return max_profit;
    }
};
