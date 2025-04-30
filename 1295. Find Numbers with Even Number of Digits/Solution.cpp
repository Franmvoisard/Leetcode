// Time: O(n log m)
// Space: O(1)

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int digits = 0;
            while(num > 0){
                num /= 10;
                digits++;
            }
            if(digits % 2 == 0) result++;
        }
        return result;
    }
};
