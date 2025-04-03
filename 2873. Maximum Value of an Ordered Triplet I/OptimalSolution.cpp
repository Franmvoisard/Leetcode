class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        long long iminusj = 0;
        int n = nums.size();
        long long res = 0;

        for(int k = 0; k < n; k++){
            res = max(res, iminusj * nums[k]);
            iminusj = max(iminusj, maxi - nums[k]);
            maxi = max(maxi, static_cast<long long> (nums[k]));
        }
        return res;
    }
};
