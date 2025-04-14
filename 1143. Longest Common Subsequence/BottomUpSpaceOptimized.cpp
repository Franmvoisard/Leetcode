class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // n = text1.size() | text2.size()
        // Time: O(n * m)
        // Space: O(m)
        vector<int> currentRow(text2.size() + 1, 0);
        int longest = 0;

        for(int row = text1.size() - 1; row >= 0; row--){
            int currentLength = 0;
            for(int col = text2.size() - 1; col >= 0; col--){
                if(currentLength < currentRow[col]) {
                    currentLength = currentRow[col];
                }
                else if(text1[row] == text2[col]){
                    currentRow[col] = 1 + currentLength;
                    longest = max(longest, currentLength + 1);
                }
            }
        }
        return longest;
    }
};
