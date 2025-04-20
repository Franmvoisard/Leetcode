// Time: O (n)
// Space: O (1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previousElement = nums[0];
        bool foundDuplicate = false;
        int n = nums.size();
        int i = 1;
        int j = 1;

        while(i < n){
            if(nums[i] == previousElement){
                if(!foundDuplicate) {
                    foundDuplicate = true;
                    nums[j] = nums[i];
                    j++;
                }
            }
            else {
                foundDuplicate = false;
                nums[j] = nums[i];
                previousElement = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};
