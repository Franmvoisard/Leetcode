/*
    Time: O(n)
    Space: O(n)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingSize = ratings.size();
        vector<int>candies(ratingSize, 1);

        // Left to right, check if i-1 > and therefore this kid should get more candy than the previous one
        for(int i = 1; i < ratingSize; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] += candies[i-1];
            }
        }
        // Right to left, check if i+1 <= and therefore this kid should get more candy than the next one IF and only if it has not currently more candy.
        for(int i = ratingSize - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1] + 1;
            }
        }
      
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
