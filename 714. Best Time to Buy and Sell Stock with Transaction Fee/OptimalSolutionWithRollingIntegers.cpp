class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Time: O(n)
        // Space: O(1)
        int n = prices.size();
        int hold = -prices[0];
        int cash = 0;

        for(int day = 0; day < n; day++){
            hold = max(hold, cash -prices[day]);
            cash = max(cash, hold + prices[day] - fee);
        }
        return cash;
    }
};
