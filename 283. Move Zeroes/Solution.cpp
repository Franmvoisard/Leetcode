class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroElementIndex = 0;
        int currentElementIndex = 0;

        while(currentElementIndex < nums.size()){
            if(nums[currentElementIndex] != 0){
               swap(nums[currentElementIndex], nums[lastNonZeroElementIndex]);
               lastNonZeroElementIndex++;
            }
            currentElementIndex++;
        }
    }
