class Solution {
private:
  // Time: O (2^n)
  // Space: O(n)
  inline int countXORSubsetsTotal(vector<int>& nums, int index, int total){
            if(index == nums.size()) return total;
            int includeIndex = countXORSubsetsTotal(nums, index+1, total ^ nums[index]);
            int excludeIndex = countXORSubsetsTotal(nums, index+1, total);
            return includeIndex + excludeIndex;
        }
public:
    int subsetXORSum(vector<int>& nums) {
        return countXORSubsetsTotal(nums, 0, 0);
    }
};
