//Time : O(nlogn)
//Space: O(1)

class Solution {
    int binary_search(int left, int right, vector<int>& array, int target){
        while(left <= right){
            int m = left + (right - left) / 2;
            if(array[m] < target){
                left = m + 1;
            }
            else {
                right = m-1;                
            }
        }
        return right;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result  = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end()); //O (nlogn)

        for(int i = 0; i < n - 1; i++){
            long long upperIndex = binary_search(i+1, n-1, nums, upper - nums[i] + 1);
            long long lowerIndex = binary_search(i+1, n-1, nums, lower - nums[i]);
            result += upperIndex - lowerIndex;
        }
        return result;
    }
};
