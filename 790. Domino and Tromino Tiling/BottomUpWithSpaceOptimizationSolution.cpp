class Solution {
public:
    int numTilings(int n) {
        // Time O(n)
        // Space O(1)
        if(n < 3) return n;
        constexpr long long c_mod = 1e9+7;
        
        long long nValidTilings = 0;        
        long long nMinusOneValidTilings = 2;        
        long long nMinusTwoValidTilings = 1;

        long long nIncompleteTilings = 1;
        long long nMinusOneIncompleteTilings = 1;
        for(int i = 3; i <= n; i++){
            nValidTilings = (nMinusOneValidTilings + nMinusTwoValidTilings + (2l * nMinusOneIncompleteTilings)) % c_mod;
            nIncompleteTilings = (nMinusOneIncompleteTilings + nMinusTwoValidTilings) % c_mod;;

            nMinusTwoValidTilings = nMinusOneValidTilings;
            nMinusOneValidTilings = nValidTilings;
            nMinusOneIncompleteTilings = nIncompleteTilings;
        }
        return nValidTilings;
    }
};
