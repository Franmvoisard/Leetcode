class Solution {
public:
// Time O(n)
// Space O(1)

    int rob(vector<int>& nums) {
        int rob1, rob2 = 0;

        for(int i = 0; i < nums.size(); i++){
            int temp =  max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp; 
        }
        return rob2;
    }
};
