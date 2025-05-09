class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;

        for(int i = 0; i < numRows; i++){
            vector<int> row = vector<int>(i + 1, 1);

            for(int j = i - 1; j > 0; j--) {
                row[j] = results[i - 1][j - 1] + results[i - 1][j];
            }
            results.push_back(row);
        }

        return results;
    }
};
