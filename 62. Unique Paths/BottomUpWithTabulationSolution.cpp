class Solution {
public:
  // Time O(m * n)
  // Space O (m * n)
    int uniquePaths(int m, int n) {
        vector<vector<int>> rows(m, vector<int>(n, 1));

        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                rows[i][j] = rows[i][j+1] + rows[i+1][j];
            }
        }
        return rows[0][0];
    }
};
