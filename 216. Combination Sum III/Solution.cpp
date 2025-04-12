class Solution {
// Time: O(2^9)
// Space: O(1) (Without counting the output) Otherwise O(k) for recursion stack and O(combinations * k) for the result
private:
    void backtrack(int index, const int& expectedSize, vector<int>& currentCombination, int combinationSum, const int& target, vector<vector<int>>& result){
        if(combinationSum == target && currentCombination.size() == expectedSize){
            result.push_back(currentCombination);
            return;
        }
        if(index > 9 || combinationSum > target || currentCombination.size() > expectedSize) return;
        currentCombination.push_back(index);
        backtrack(index + 1, expectedSize, currentCombination, combinationSum + index, target, result);
        currentCombination.pop_back();
        backtrack(index + 1, expectedSize, currentCombination, combinationSum, target, result);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(1, k, currentCombination, 0, n, result);
        return result;
    }

};
