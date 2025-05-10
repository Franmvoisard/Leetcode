// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
private:
    int findNextElement(const int& target, int left, vector<int>& prefixSum){
        int right = prefixSum.size() - 1;
        int result = -1;
        while(left <= right){
            int m = (right + left) / 2;
            if(prefixSum[m] >= target) {
                right = m-1;
                result = m;
            }
            else {
                left = m + 1;
            }
        }
        return result;
    };

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int inputSize = nums.size();
        vector<int> prefixSum(inputSize+1, 0);
        int minSubArray = INT_MAX;

        //Build prefix sum
        for(int i = 1; i < inputSize + 1; i++){
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        }

        //Bin-search for the minimum possible compatible index
        for(int i = 0; i < prefixSum.size(); i++){
            int expected = prefixSum[i] + target;
            int result = findNextElement(expected, i, prefixSum);
            if(result != -1) minSubArray = min(minSubArray, result - i);
        }
        return minSubArray == INT_MAX ? 0 : minSubArray;
    }
};
