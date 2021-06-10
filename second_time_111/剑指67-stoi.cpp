class Solution {
public:
    int strToInt(string str) {
        str = str.erase(0, str.find_first_not_of(' '));
        if(str.empty())
            return 0;
        int flag = 1, idx = 1;
        if(str[0] == '-') flag = -1;
        else if(str[0] != '+') idx = 0;

        int res = 0;
        int bound = INT_MAX / 10;
        for(int i = idx; i < str.size(); ++i) {
            if(str[i] - '0' < 0 || str[i] - '9' > 0) break;
            if(res > bound || (res == bound && str[i] - '0' > 7))
                return flag == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (str[i] - '0');
        }
        return flag * res;
    }
};
class Solution {
    public int strToInt(String str) {
        int res = 0, bndry = Integer.MAX_VALUE / 10;
        int i = 0, sign = 1, length = str.length();
        if(length == 0) return 0;
        while(str.charAt(i) == ' ')
            if(++i == length) return 0;
        if(str.charAt(i) == '-') sign = -1;
        if(str.charAt(i) == '-' || str.charAt(i) == '+') i++;
        for(int j = i; j < length; j++) {
            if(str.charAt(j) < '0' || str.charAt(j) > '9') break;
            if(res > bndry || res == bndry && str.charAt(j) > '7')
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            res = res * 10 + (str.charAt(j) - '0');
        }
        return sign * res;
    }
}

作者：jyd
链接：https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/solution/mian-shi-ti-67-ba-zi-fu-chuan-zhuan-huan-cheng-z-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。