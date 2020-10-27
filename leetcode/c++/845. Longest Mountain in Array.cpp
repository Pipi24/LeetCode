/*
对于一座「山脉」，我们称首元素 B[0] 和尾元素 B[len(B)−1] 为「山脚」，满足题目要求 B[i−1]<B[i]>B[i+1] 的元素 B[i] 为「山顶」。
为了找出数组 A 中最长的山脉，我们可以考虑枚举山顶，再从山顶向左右两侧扩展找到山脚。

由于从左侧山脚到山顶的序列是严格单调递增的，而从山顶到右侧山脚的序列是严格单调递减的，因此我们可以使用动态规划（也可以理解为递推）的方法，计算出从任意一个元素开始，向左右两侧最多可以扩展的元素数目。

我们用 left[i] 表示 A[i] 向左侧最多可以扩展的元素数目。如果 A[i−1]<A[i]，那么 A[i] 可以向左扩展到 A[i−1]，再扩展 left[i-1] 个元素，因此有
left[i]=left[i−1]+1

如果 A[i−1]≥A[i]，那么 A[i]A[i] 无法向左扩展，因此有
left[i]=0
特别地，当 i=0 时，A[i] 为首元素，无法向左扩展，因此同样有
left[0]=0

右侧类似

时间复杂度：O(n)，其中 n 是数组 A 的长度。
空间复杂度：O(n)，即为数组 left 和 right 需要使用的空间。

*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int length = A.size();
        if(length<3)
            return 0;
        vector<int> left(length,0);
        for(int i=1; i<length;++i)
            left[i] = A[i-1]<A[i]?left[i-1]+1:0;
        
        vector<int> right(length,0);
        for(int i=length-2; i>=0;--i)
            right[i] = A[i]>A[i+1]?right[i+1]+1:0;
        
        int ans = 0;
        for(int i=1; i<length-1; ++i){
            if(left[i]>0 && right[i]>0){
                ans = max(ans, left[i]+right[i]+1);
            }
        }
        return ans;
    }
};

/*
我们也可以枚举山脚。例如当我们从左向右遍历整个数组 A 时，可以使用双指针的方法，一个指针枚举左侧山脚，另一个指针不断向右移动到右侧山脚

具体地，我们使用指针 left 指向左侧山脚，它的初始值为 0。每次当我们固定 left 时：

我们首先需要保证left+2<n，这是因为山脉的长度至少为 3；其次我们需要保证A[left]<A[left+1]，否则 left 对应的不可能时左侧山脚；

我们将右侧山脚的right 的初始值置为 left+1，随后不断地向右移动right，直到不满足 A[right]<A[right+1] 为止，此时：

如果 right=n−1，说明我们已经移动到了数组末尾，已经无法形成山脉了；

否则，right 指向的可能是山顶。我们需要额外判断是有满足A[right]>A[right+1]，这是因为如果两者相等，那么 right 指向的就不是山顶了。

如果 right 指向的确实是山顶，那么我们使用类似的方法，不断地向右移动 right，直到不满足 A[right]>A[right+1] 为止，此时，right 指向右侧山脚，A[left] 到 A[right] 就对应着一座山脉；

需要注意的是，右侧山脚有可能是下一个左侧山脚，因此我们需要将 right 的值赋予 left，以便与进行下一次枚举。
在其它所有不满足要求的情况下，right 对应的位置都不可能是下一个左侧山脚，因此可以将 right+1 的值赋予 left。

在下面的代码中，当不满足要求时，我们立即将 right 的值加 1。这样一来，我们就可以统一在下一次枚举左侧山脚之前，将 right 的值赋予 left 了。

时间复杂度：O(n)，其中 nn 是数组 A 的长度
空间复杂度：O(1)。
*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int left = 0;
        while (left + 2 < n) {
            int right = left + 1;
            if (A[left] < A[left + 1]) {
                while (right + 1 < n && A[right] < A[right + 1]) {
                    ++right;
                }
                if (right < n - 1 && A[right] > A[right + 1]) {
                    while (right + 1 < n && A[right] > A[right + 1]) {
                        ++right;
                    }
                    ans = max(ans, right - left + 1);
                }
                else {
                    ++right;
                }
            }
            left = right;
        }
        return ans;
    }
};