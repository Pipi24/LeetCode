class Solution {
public:
    int myAtoi(string str) {
        long long num = 0;
        int flag = 0;
        int i = 0;
        while(str[i] == ' ')
            ++i;
        if(str[i] == '+')
            flag = 1;
        else if(str[i] == '-')
            flag = -1;
        else if(str[i] >= '0'&&str[i]<='9')
            num = num*10 + str[i] - '0';
        else
            return 0;
        
        while(i<str.length()){
            if(str[i] >= '0'&&str[i]<='9'){
                num = num*10 + str[i] - '0';
                if(flag == 1 && flag*num >= INT_MAX)
                    return INT_MAX;
                if(flag == -1 && flag*num <= INT_MIN)
                    return INT_MAX;
            }
            ++i;
        }
        return flag*num;
    }
};