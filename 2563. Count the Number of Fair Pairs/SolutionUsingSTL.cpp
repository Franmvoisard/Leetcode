// Time: O(nlogn)
// Space: O(1), O (logn) if sort stack taken into account
class Solution {

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result  = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end()); //O (nlogn)

        for(int i = 0; i < n - 1; i++){
            auto upperIndex = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto lowerIndex = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            result += upperIndex - lowerIndex;
        }
        return result;
    }
};
