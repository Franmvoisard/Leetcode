class Solution {
public:
    // Space O(n)
    // Time O(n)
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> numbers;
        int n = nums.size();

        for(auto num : nums){
            if(num < k) return -1;
            else if(num > k) {
                numbers.insert(num);
            }
        }
        return numbers.size();
    }
};
