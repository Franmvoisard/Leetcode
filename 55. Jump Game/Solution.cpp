//Time: O(n)
//Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n =  nums.size();

        for(int i = 0; i < n-1; i++){
            if(i <= farthest){
                farthest = max(farthest, i + nums[i]);
            }
        }
        return farthest >= n-1;
    }
};
