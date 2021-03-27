class Solution {
public:

    // 取数值各个位上的单数之和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};


class Solution {
    int calNum(int n){
        int ans = 0;
        while(n){
            ans += (n % 10)*(n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = calNum(slow);
            fast = calNum(fast);
            fast = calNum(fast);
        }while(slow != fast);
        return slow == 1;
    }
};
