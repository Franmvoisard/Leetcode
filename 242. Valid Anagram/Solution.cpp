class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> frequencyMapS;
        unordered_map<char, int> frequencyMapT;

        for(int i = 0 ; i < s.size(); i++){
            frequencyMapS[s[i]]++;
            frequencyMapT[t[i]]++;
        }
        
        return frequencyMapS == frequencyMapT;
    }
};
