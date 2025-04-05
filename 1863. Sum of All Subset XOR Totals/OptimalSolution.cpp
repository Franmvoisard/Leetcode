class Solution {
public:
  // Time O(n)
  // Space O(1)
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for(int num : nums){
            result |= num;
        }
        return result << (nums.size()-1);
    }

};
