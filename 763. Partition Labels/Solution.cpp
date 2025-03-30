class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> lastSeen;
        vector<int> result;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i]] = i;
        }

        int size = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, lastSeen[s[i]]);

            if(i == end){
                result.push_back(size);
                size = 0;
            }
        }

        return result;
    }
};
