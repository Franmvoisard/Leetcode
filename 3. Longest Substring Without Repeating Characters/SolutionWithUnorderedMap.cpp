// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int inputSize = s.size();
        unordered_map<char, int> lastSeenIndex;
        int longestSubstring = 0;

        for(int right = 0; right < inputSize; right++){
            char currentChar = s[right];
            
            if(lastSeenIndex.count(currentChar) && left <= lastSeenIndex[currentChar]){
                left = lastSeenIndex[currentChar] + 1;                
            }
            lastSeenIndex[currentChar] = right;
            longestSubstring = max(longestSubstring, (right - left) + 1);
        }
        return longestSubstring;
    }
};
