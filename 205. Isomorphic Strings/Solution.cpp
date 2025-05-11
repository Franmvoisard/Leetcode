// Time complexity O(N)
// Space complexity O(UC) where UC are unique characters
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> frequencyMapS;
        unordered_map<char, int> frequencyMapT;
        int stringLength = s.size();
        
        for(int i = 0; i < stringLength; i++){
            if(!frequencyMapS.count(s[i])){
                frequencyMapS[s[i]] = i;
            }
            if(!frequencyMapT.count(t[i])){
                frequencyMapT[t[i]] = i;
            }

            if(frequencyMapS[s[i]] != frequencyMapT[t[i]]) return false;
        }
        return true;
    }
};
