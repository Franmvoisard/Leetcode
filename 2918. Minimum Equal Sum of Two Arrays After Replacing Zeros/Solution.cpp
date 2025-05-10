// Time: O(n + m)
// Space: O(1)
class Solution {
private:
    static const void countSumAndZeroes(const vector<int>& nums,
                                long long& sumAccumulator,
                                int& zeroCount) {
        for (int num : nums) {
            sumAccumulator += num;
            if (num == 0) zeroCount++;
        }
    }

public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroCount1 = 0, zeroCount2 = 0;
        long long sum1 = 0, sum2 = 0;

        //Count and precompute sums
        countSumAndZeroes(nums1, sum1, zeroCount1);
        countSumAndZeroes(nums2, sum2, zeroCount2);

        long long nums1minSum = sum1 + zeroCount1;
        long long nums2minSum = sum2 + zeroCount2;

        if (nums1minSum < nums2minSum && zeroCount1 == 0) return -1;
        if (nums2minSum < nums1minSum && zeroCount2 == 0) return -1;

        return max(sum1 + zeroCount1, sum2 + zeroCount2);
    }
};
