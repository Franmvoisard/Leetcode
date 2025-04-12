class Solution {
    // Time O(2^n)
    // Space O(n)

    private:
        void backtrack(int index, vector<int>& candidates, int& target, vector<int>& currentCombination, int totalSum, vector<vector<int>>& result){
            if(totalSum == target) {
                result.push_back(currentCombination);
                return;
            }
            if(index >= candidates.size() || totalSum > target) return;
        
            currentCombination.push_back(candidates[index]);
            backtrack(index, candidates, target, currentCombination, totalSum + candidates[index], result);
            currentCombination.pop_back();
            backtrack(index + 1, candidates, target, currentCombination, totalSum, result);
        }
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        int totalSum = 0;
        backtrack(0, candidates, target, currentCombination, totalSum, result);
        return result;
    }
};
