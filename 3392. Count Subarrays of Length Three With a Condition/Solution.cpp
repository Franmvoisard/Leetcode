// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {

        int count = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = nums[i];
            int half = nums[i + 1];
            int right = nums[i + 2];

            if (left * 2 + right * 2 == half) {
                count++;
            }
        }
        return count;
    }
};
