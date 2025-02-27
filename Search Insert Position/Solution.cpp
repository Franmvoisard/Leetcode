class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();

        while(start < end){
            int middle = start + (end - start) / 2;

            if(nums[middle] >= target) {
                end = middle;
            }
            else {
                start = middle + 1;
            }
        }
        return start;
    }
};
