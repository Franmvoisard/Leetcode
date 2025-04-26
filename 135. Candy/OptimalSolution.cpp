/*
    Time: O(n)
    Space: O(1)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingSize = ratings.size();
        int up = 0, down = 0, peak = 0;
        int candies = 1;

        for(int i = 1; i < ratingSize; i++){
            if(ratings[i] > ratings[i-1]){ //going up
                up++;
                peak = up;
                down = 0;
                candies += 1;
            }
            else if(ratings[i] < ratings[i-1]){
                up = 0;
                down++;
                //if our valley is bigger than the peak, then we compesate with 1 extra candy
                if(down > peak) candies++;
                candies += down;
            }
            else {
                up = 0;
                down = 0;
                peak = 0;
                candies++;
            }
        }
        return candies;
    }
};
