class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> results(candies.size(), false);
        int highestCandiesAmount =  *max_element(candies.begin(), candies.end());;

        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= highestCandiesAmount){ 
                results[i] = true;
            }
        } 
        return results;
    }
};
