class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> frequenciesCount;
        for (int element : arr) {
            map[element]++;
        }

        for (auto it : map) {
            if (frequenciesCount.contains(it.second))
                return false;
            else {
                frequenciesCount.insert(it.second);
            }
        }
        return true;
    }
};
