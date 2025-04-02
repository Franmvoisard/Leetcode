class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int left = nums[0];
        // Time O (n^2)
        // Space O (1)

        for(int j = 1; j < n; j++){
            if(nums[j] > left) {
                left = nums[j];
                continue;
            }

            for(int k = j+1; k < n; k++){
                res = max(res, (long long)(left - nums[j]) * nums[k]);
            }
        }
        return res;
    }
};
