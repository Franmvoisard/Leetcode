class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int m = left + (right - left ) / 2;
            int element = nums[m];
            if(element == target) return m;
            if(element < target){
                left = m + 1;
            }
            else {
                right = m - 1;
            }
        }

        return -1;
    }
};
