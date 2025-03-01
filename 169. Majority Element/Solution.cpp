class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m;
        int c= 0;
        for(int i = 0; i < nums.size(); i++){
            if(c == 0) {
                m = nums[i];
                c = 1;
            }
            else if (m == nums[i]){
                c= c+1;
            }
            else {
                c = c - 1;
            }
        }
        return m;
    }
};