// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int left = 0;
        int longestSubstringWithUniqueCharacters = 0;

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];
            while(charset.contains(currentChar)){
                charset.erase(s[left]);
                left++;
            }
            charset.insert(currentChar);
            longestSubstringWithUniqueCharacters = max(longestSubstringWithUniqueCharacters, (right - left) + 1);
        }
        return longestSubstringWithUniqueCharacters;
    }
};
