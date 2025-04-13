class Solution {
public:
    int numTilings(int n) {
        // Time O(n)
        // Space O(n)
        constexpr long long c_mod = 1e9+7;
        
        vector<long long> validTilings = {0,1,2};
        vector<long long> incompleteTilings = {0,0,1};

        for(int i = 3; i <= n; i++){
            validTilings.push_back((validTilings[i-1] + validTilings[i-2] + (2l * incompleteTilings[i-1])) % c_mod);
            incompleteTilings.push_back(incompleteTilings[i-1] + validTilings[i-2]);
        }
        return validTilings[n];
    }
};
