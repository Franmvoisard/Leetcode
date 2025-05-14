// Time complexity: O(n)
// Space complexity: O(k)
class Solution {
public:
    string minWindow(string s, string t) {
        
        //Not possible to find a valid subarray.
        if (t.size() > s.size()) return "";
        
        int minSubArrayLength = INT_MAX;
        int minSubArrayIndex = 0;
        
        // Create and fill target frequency
        int required = 0;
        vector<int> targetFrequency(128, 0);
        
        // Count uniques and fill frequencies
        for (char c : t) {
            if(targetFrequency[c]++ == 0) required++;
        }

        vector<int> currentWindowFrequencies(128, 0);
        int charactersTargetsReached = 0;
        int left = 0;
        
        // Grow window
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (targetFrequency[c] > 0) {
                currentWindowFrequencies[c]++;
                if (currentWindowFrequencies[c] == targetFrequency[c]) {
                    charactersTargetsReached++;
                }
            }
            
            // Shrink window until we drop one letter
            while (charactersTargetsReached == required) {
                int windowLength = right - left + 1;
                if (windowLength < minSubArrayLength) {
                    minSubArrayLength = windowLength;
                    minSubArrayIndex = left;
                }

                char leftChar = s[left];
                if (targetFrequency[leftChar] > 0) {
                    if (currentWindowFrequencies[leftChar] == targetFrequency[leftChar]) {
                        charactersTargetsReached--;
                    }
                    currentWindowFrequencies[leftChar]--;
                }
                left++;
            }
        }

        return minSubArrayLength == INT_MAX ? "" : s.substr(minSubArrayIndex, minSubArrayLength);
    }
};
