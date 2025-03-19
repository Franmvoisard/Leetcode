class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;

        for(int right = 0; right < n - 2; right++){
            if(nums[right] == 0){
                for(int i = right; i < right + 3; i++){
                    nums[i] ^= 1;
                }
                flips++;
            }
        }
        return min(nums[n-1], nums[n-2]) == 1 ? flips : -1;
    }
};
