class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // Time: O(text1 * text2)
        // Space: O(text2)
        vector<int> currentRow(text2.size() + 1, 0);
        vector<int> previousRow(text2.size() + 1, 0);

        for(int row = text1.size() - 1; row >= 0; row--){
            for(int col = text2.size() - 1; col >= 0; col--){
                if(text1[row] == text2[col]){
                    currentRow[col] = 1 + previousRow[col + 1];
                }
                else {
                    currentRow[col] = max(currentRow[col + 1], previousRow[col]);
                }
            }
            previousRow = currentRow;
        }
        return currentRow[0];
    }
};
