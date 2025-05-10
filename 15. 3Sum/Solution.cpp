//Time Complexity:  O(n^2)
//Space Complexity: O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){
            if (nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue; //Skip duplicates
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int totalSum = nums[i] + nums[j] + nums[k];
                if(totalSum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j]) j++; //Skip j duplicates
                    while(j < k && nums[k+1] == nums[k]) k--; //Skip k duplicates
                }
                else if(totalSum > 0){
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return result;
    }
};
