class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        //一次交易至少两天，因此K大于len/2的话相当于没有限制，这里解决爆内存的问题
        if(K > len/2){
            int opt_i_0 = 0;
            int opt_i_1 = -prices[0];
            for(int i=1; i<len; ++i){
                int temp = opt_i_0;
                opt_i_0 = max(opt_i_0, opt_i_1 + prices[i]);
                opt_i_1 = max(opt_i_1, opt_i_0 - prices[i]);
            }
            return opt_i_0;
        }

        vector<vector<vector<int>>> opt(len, vector<vector<int>>(K+1, vector<int>(2,0)));
        for(int k = 0; k < K+1; ++k){
            opt[0][k][0] = 0;
            opt[0][k][1] = -prices[0];
        }
        for(int i = 1; i < len; ++i){
            for(int k = K; k > 0; --k){
                opt[i][k][0] = max(opt[i-1][k][0], opt[i-1][k][1] + prices[i]);
                opt[i][k][1] = max(opt[i-1][k][1], opt[i-1][k-1][0] - prices[i]);
            }
        }
        return opt[len-1][K][0];
    }
};