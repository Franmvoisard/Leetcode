// Time: O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int finalWordLength = 0;
    
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
              finalWordLength++;
            }
            else if {(finalWordLength > 0) {
                break;
            }
        }
        return finalWordLength;
    }
};
