class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewelsCount = 0;
        unordered_set<char> jewelsSet;
        int jewelsLength = J.length(), stonesLength = S.length();
        for (int i = 0; i < jewelsLength; i++) {
            char jewel = J[i];
            jewelsSet.insert(jewel);
        }
        for (int i = 0; i < stonesLength; i++) {
            char stone = S[i];
            if (jewelsSet.count(stone)) {
                jewelsCount++;
            }
        }
        return jewelsCount;
    }
};
