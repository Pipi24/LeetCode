class Solution {
public:
    class cmp{
        public:
            bool operator()(const pair<int,int> l, const pair<int,int>r){
                return l.second > r.second;       
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); ++i){
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int, int> >, cmp> pri_que;
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k)
                pri_que.pop();
        }
        vector<int> res;
        while(!pri_que.empty()){
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
