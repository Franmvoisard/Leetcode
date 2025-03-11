class Solution {

public:
    int equalPairs(vector<vector<int>>& grid) {
    
        map<vector<int>, int> map;
        int n = grid.size();
        int result = 0;

        for(int i = 0; i < n; i++){
            map[grid[i]]++;
        }
        
        for(int i = 0; i < n; i++){
            vector<int> col(n);
            for(int j = 0; j < n; j++){
                col[j] = grid[j][i];
            }
            result += map[col];
        }
        return result;
    }
};
