class Solution {
public:
    // Time: O (m * n)
    // Space: O (n)

    int uniquePaths(int m, int n) {
        vector<int> rows(n, 1);

        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                rows[j] += rows[j+1];
            }
        }
        return rows[0];
    }
};
