class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int totalSum = 0;
        vector<int> numbers(grid.size() * grid.size() +1);
        vector<int> result(2);

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                int num = grid[i][j];

                if(numbers[num] == 1){
                    result[0] = num;
                }
                else {
                    totalSum += num;
                }
                numbers[num]++;
            }
        }
        int expectedResult = ((grid.size() * grid.size()) * (grid.size() * grid.size() +1)) / 2;
        result[1] =  expectedResult - totalSum;
        return result;
    }
};
