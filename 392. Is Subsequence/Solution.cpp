// Time Complexity: O(N)
// Space Complexity : O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;

        int targetIndex = 0;       

        for (auto currentChar : t) {
            if (currentChar == s[targetIndex]) {
                targetIndex++;

                if (targetIndex == s.size()){
                    return true;
                }
            }
        }
        return false;
    }
};
