class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> result = vector<int>(rowIndex + 1,0);
       result[0] = 1;
       for(int i = 1; i <= rowIndex; i++) {
            for(int j = i; j >= 1; j--) {
                result[j] += result[j-1]; 
            }
        }
       return result;
    }
};
