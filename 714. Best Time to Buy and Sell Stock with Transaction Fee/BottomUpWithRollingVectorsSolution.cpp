class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Time: O(n)
        // Space: O(1)
        
        int n = prices.size();
        vector<int> currentDay(2,0);
        vector<int> lastDay(2,0);
        for(int day = n-1; day >= 0; day--){
            currentDay[true] = max(prices[day] + lastDay[false] - fee, lastDay[true]);
            currentDay[false] = max(-prices[day] + lastDay[true], lastDay[false]);
            lastDay = currentDay;
        }
        return currentDay[false];
    }
};
