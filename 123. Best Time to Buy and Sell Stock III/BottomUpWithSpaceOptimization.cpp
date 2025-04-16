class Solution {

public:
    // Time: O(n)
    // Space: O(1)

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> lastDay(3, vector<int>(2, 0));
        vector<vector<int>> currentDay(3, vector<int>(2, 0));
        int result = 0;
        int n = prices.size();
        for(int day = n-1; day >= 0; day--){
            for(int transactionsLeft = 2; transactionsLeft > 0; transactionsLeft--){
                //Max profit if we hold
                currentDay[transactionsLeft][1] = max(lastDay[transactionsLeft][1], prices[day] + lastDay[transactionsLeft - 1][0]);
                //Max profit if we do not hold
                currentDay[transactionsLeft][0] = max(lastDay[transactionsLeft][0], -prices[day] + lastDay[transactionsLeft][1]);
            }
            lastDay = currentDay;
        }
        return currentDay[2][0];
    }
};
