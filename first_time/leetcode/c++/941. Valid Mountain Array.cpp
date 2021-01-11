class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
            return false;
        //初始为上山
        bool up = true;
        for(int i=0; i<A.size()-1;++i){
            if(up){
                //到达山顶
                if(A[i]>=A[i+1]){
                    //若山顶是数组的第0个数 [9,8,7]，则不是山脉
                    if(i==0)
                        return false;
                    //变为下山
                    up=false;
                    //退到山顶，重新判断下山条件
                    i--;
                }
            }
            else{
                //下山过程中遇到上山或者平路
                if(A[i]<=A[i+1])
                    return false;
            }
        }
        //!up 表示是否是在下山 [7,8,9]
        return !up;
    }
};

/*
按题意模拟即可。我们从数组的最左侧开始向右扫描，直到找到第一个不满足 A[i]<A[i+1] 的下标 i，那么 i 就是这个数组的最高点的下标。
如果 i=0 或者不存在这样的 i（即整个数组都是单调递增的），那么就返回 false。
否则从 i 开始继续向右扫描，判断接下来的的下标 j 是否都满足 A[j]>A[j+1]，若都满足就返回 true，否则返回 false。

*/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;

        // 递增扫描
        while (i + 1 < N && A[i] < A[i + 1]) {
            i++;
        }

        // 最高点不能是数组的第一个位置或最后一个位置
        if (i == 0 || i == N - 1) {
            return false;
        }

        // 递减扫描
        while (i + 1 < N && A[i] > A[i + 1]) {
            i++;
        }

        return i == N - 1;
    }
};
