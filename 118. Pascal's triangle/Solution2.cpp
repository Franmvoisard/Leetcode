class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        results.push_back(vector<int>({1}));

        for(int i = 0; i < numRows - 1; i++)
        {
            results.push_back(calculateRowValues(results[i]));
        }

        return results;
    }

    vector<int> calculateRowValues(vector<int>& rowValues){

        vector<int> results;

        for(int i = 0; i <= rowValues.size(); i++){
            if(i == 0 || i == rowValues.size()){
                results.push_back(1);
            }
            else {
                int sum = rowValues[i-1] + rowValues[i];
                results.push_back(sum);
            }
        }
        return results;
    }
};
