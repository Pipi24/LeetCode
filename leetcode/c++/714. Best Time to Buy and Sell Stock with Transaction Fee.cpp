class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if(len == 0)
            return 0;
        int opt_i_0 = 0;
        int opt_i_1 = -prices[0];
        for(int i=1; i<len; ++i){
            int temp = opt_i_0;
            opt_i_0 = max(opt_i_0, opt_i_1 + prices[i] - fee);
            opt_i_1 = max(opt_i_1, temp - prices[i]);
        }
        return opt_i_0;
    }
};