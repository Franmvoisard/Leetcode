class Solution {
public:
    // Time Complexity O(N * log M)
    // Space Complexity O (1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        long long right = *max_element(piles.begin(), piles.end());
        long long result = 0;

        while(left <= right){
            int bananasToEat = left + (right - left ) / 2;
            long long hoursSum = 0;

            for(int i = 0; i < piles.size(); i++){
                hoursSum += ceil( (piles[i] + bananasToEat - 1LL) / bananasToEat);
            }

            if(hoursSum <= h){
                result = bananasToEat;
                right = bananasToEat - 1;
            }
            else {
                left = bananasToEat + 1;
            }
        }
        return result;
    }
};

