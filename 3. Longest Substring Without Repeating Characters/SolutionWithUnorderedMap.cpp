class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.size(); right++){
            char currentCharacter = s[right];
            auto it = map.find(currentCharacter);

            if(it != map.end() && it->second >= left){ 
                left = it->second + 1;
                map[currentCharacter] = right;
            }
            else {
                map[currentCharacter] = right;            
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
