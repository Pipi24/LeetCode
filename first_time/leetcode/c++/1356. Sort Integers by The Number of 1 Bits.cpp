/*
前言
题目本身很简单，只要调用系统自带的排序函数，然后自己改写一下排序规则即可，所以这里主要讲讲如何计算数字二进制下 1 的个数 。

方法一：暴力
对每个十进制的数转二进制的时候统计一下 1 的个数即可。

*/
class Solution {
public:
    int get(int x){
        int res = 0;
        while (x) {
            res += (x % 2);
            x /= 2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (auto x: arr) {
            bit[x] = get(x);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};

/*
方法二：递推预处理
我们定义 bit[i] 为数字 ii 二进制表示下数字 1 的个数，则可以列出递推式：

bit[i]=bit[i>>1]+(i&1)

所以我们线性预处理 bitbit 数组然后去排序即可。

*/
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1;i <= 10000; ++i) {
            bit[i] = bit[i>>1] + (i & 1);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};


//自定义规则的另一种写法
vector<int> bit = vector<int>(10001, 0);

class Custom{
public:
    bool operator() (int x,int y){
        if (bit[x] < bit[y]) {
            return true;
        }
        if (bit[x] > bit[y]) {
            return false;
        }
        return x < y;
    }
};
class Solution {
public:

    int get(int x){
        int res = 0;
        while (x) {
            res += (x % 2);
            x /= 2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        for (auto x: arr) {
            bit[x] = get(x);
        }
        sort(arr.begin(),arr.end(),Custom());
        return arr;
    }
};
