class Solution {
public:
    int numTrees(int n) {
        vector<int> opt(n+1, 0);
        //因为递归是乘法，得初始化为1
        opt[0]=1;
        opt[1]=1;
        
        for(int i = 2; i<=n; ++i){
            //不能从0开始，因为这里要求opt[i]，为0的话表达式也有opt[i]，本身不满足递推表达式
            for(int j = 1; j<=i; ++j){
                opt[i] += opt[j-1] * opt[i-j];
            }
        }
        return opt[n];
    }
};