class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min;
        uint maxProfit = 0;
        min = prices[0];


        for(int i = 1; i < prices.size(); i++){

            if(prices[i] < min){
                min = prices[i];
            }
            if(prices[i] - min > maxProfit){
                maxProfit = prices[i] - min;
            }
            
        }

        return maxProfit;
    }
};
