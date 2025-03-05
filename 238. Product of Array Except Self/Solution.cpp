class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int postfix = 1;
        vector<int> results(nums.size());

        for(int i = 0; i < nums.size(); i++){
            results[i] = prefix;
            prefix *= nums[i];
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            results[i] *= postfix;
            postfix *= nums[i];
        }
        return results;
    }
};
