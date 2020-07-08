/*
首先考虑两种边界情况。

如果 k=0k=0，则不能建造任何跳水板，因此返回空数组。

如果 shorter 和 longer 相等，则建造的跳水板的长度是唯一的，都等于 shorter∗k，因此返回长度为 1 的数组，数组中的元素为 shorter∗k。

然后考虑一般情况，即 shorter<longer 且k>0。由于短木板和长木板一共使用 k 块，因此一共有 k+1 种组合，每种组合下建造的跳水板长度都是不一样的，一共有 k+1 种不同的长度。

length = shorter*i + longer*(k-i)

时间复杂度：O(k)
空间复杂度：O(1)
*/
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return vector <int> ();
        }

        if (shorter == longer) {
            return vector <int> (1, shorter * k);
        }

        vector <int> lengths(k + 1);
        for (int i = 0; i <= k; ++i) {
            lengths[i] = shorter * (k - i) + longer * i;
        }

        return lengths;
    }
};

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans;
        if(k==0)
            return ans;
        for(int i=k; i>=0; --i){
            ans.push_back(shorter*i + longer*(k-i));
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};