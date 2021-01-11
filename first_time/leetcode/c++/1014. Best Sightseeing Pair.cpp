/*
将我们回过头来看得分公式，我们可以将其拆分成 A[i]+i 和 A[j]−j 两部分，
这样对于统计景点 j 答案的时候，由于 A[j]−j 是固定不变的，因此最大化 A[i]+i+A[j]-j的值
其实就等价于求 [0,j-1] 中 A[i]+iA[i]+i 的最大值max_ai ，景点 j 的答案即为 mx+A[j]-j 。
而 max_ai 的值我们只要从前往后枚举 j 的时候同时维护即可，这样每次枚举景点 jj的时候，寻找使得得分最大的 i 就能从 O(n) 降至 O(1) 的时间复杂度，
总时间复杂度就能从 O(n^2) 降至 O(n)

*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max_ai = A[0]+0;
        int ans = 0;
        for(int j=1; j<A.size(); ++j){
            ans = max(ans, max_ai + A[j] - j );
            max_ai  = max(max_ai, A[j] + j);
        }
        return ans;
    }
};