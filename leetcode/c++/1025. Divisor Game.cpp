class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};


class Solution {
public:
    bool divisorGame(int N) {
        //N+2是为了初始化f[1]和f[2] 访问时不越界
        vector<int> f(N + 2, false);

        f[1] = false;
        f[2] = true;
        for (int i = 3; i <= N; ++i) {
            for (int j = 1; j < i; ++j) {
                //给bob找一个必败态
                if (i % j == 0 && !f[i - j]) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[N];
    }
};