/*关于动态规划的解法，有两个细节大家注意一下。

为什么将 dp 数组的所有元素都初始化为 amount + 1：

vector<int> dp(amount + 1, amount + 1);
这是由于 dp[amount] 最大不可能超过 amount（最小面值为 1 元），所以 amount + 1 就是一个无意义的数了。

为什么函数返回的时候判断的是 dp[amount] > amount 而不是 dp[amount] == amount + 1 呢？

return dp[amount] > amount ? -1 : dp[amount];
这里显然是可以用 dp[amount] == amount + 1 来判断的，因为我们在计算 dp 数组的每个元素时，都用到了 min 函数，
也就是说哪怕有一个元素是大于 amount + 1 的最终都会被最小化为 amount + 1，所以这里使用 dp[amount] > amount 还是 dp[amount] == amount + 1 没有区别。*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //初始化为amount+1是因为求最小，要给一个正无穷一样的值
        vector<int> opt(amount+1,amount+1);
        opt[0]=0;
        for(int i=1; i<=amount; ++i){
            for(int j=0; j<coins.size(); ++j){
                if(coins[j]<=i)
                    opt[i]=min(opt[i],opt[i-coins[j]]+1);
            }
        }
		//如果不能组成给定金额，那么给定金额在数组对应的值一定没有被修改
        return opt[amount] == amount + 1 ?-1:opt[amount];
    }
};