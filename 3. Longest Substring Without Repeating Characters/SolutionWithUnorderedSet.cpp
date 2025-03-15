class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longestSubstrSize = 0;
        unordered_set<char> charset;

        for(int right = 0; right < s.size(); right++){
            char currentCharacter = s[right];
            while(charset.contains(currentCharacter)){
                charset.erase(s[left]);
                left++;
            }

            charset.insert(currentCharacter);
            longestSubstrSize = max(longestSubstrSize, right - left + 1);
        }

        return longestSubstrSize;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
};
