class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //Time O(n)
        //Space O(n)
        bool numSeen[101]; //Using 101 due to constrains nums will be always < 100
        
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--){
            int num = nums[i];
            if(!numSeen[num]){
                numSeen[num] = true;
            }
            else {
                return (i + 3) / 3;
            }
        }
        return 0;
    }
};
