class Solution {
private:
    vector<vector<int> >combines;
    vector<int> combine;

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return combines;
    }
    void dfs(int k, int n, int cur){
        if(k==0 && n==0){
            combines.emplace_back(combine);
            return;
        }
        if(cur>9 || k<0 || n<0)
            return;
        //不选cur
        dfs(k, n, cur+1);
        //选cur
        if(k>=0 && n>=0){
            combine.emplace_back(cur);
            dfs(k-1, n-cur, cur+1);
            combine.pop_back();
        }

    }
};