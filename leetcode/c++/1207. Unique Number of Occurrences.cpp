class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(const auto& num : arr)
            map[num]++;
        unordered_map<int, int> map_dup;
        for(const auto& num_cnt : map)
            if(map_dup.find(num_cnt.second)!=map_dup.end())
                return false;
            else
                map_dup[num_cnt.second] = 1;
        return true;
    }
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (const auto& x: arr) {
            occur[x]++;
        }
        unordered_set<int> times;
        for (const auto& x: occur) {
            times.insert(x.second);
        }
        return times.size() == occur.size();
    }
};
