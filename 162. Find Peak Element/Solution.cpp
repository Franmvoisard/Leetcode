class Solution {

public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n-1;

        while(left <= right){
            int m = left + (right - left) / 2;
            int currentNum = nums[m];
            if(m > 0 && currentNum < nums[m-1]){
                right = m - 1;
            }
            else if (m < n-1 && currentNum < nums[m+1]){
                left = m + 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
};
