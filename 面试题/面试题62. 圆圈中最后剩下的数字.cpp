class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> l;
        for(int i=0; i<n; ++i)
            l.push_back(i);
        
        int index = 0;
        while(l.size()!=1){
            auto iter = l.begin();
            index = (index+m-1)%l.size();
            // 将指针从链表首部移动到索引处
            advance(iter, index);
            l.erase(iter);
        }
        return l.front();
    }
};


class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i=2; i<=n; ++i){
            ans = (ans+m)%i;
        }
        return ans;
    }
};