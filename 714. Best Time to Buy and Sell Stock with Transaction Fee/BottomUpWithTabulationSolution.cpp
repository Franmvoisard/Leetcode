class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Time: O(n)
        // Space: O(n)
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int day = n-1; day >= 0; day--){
            dp[day][true] = max(prices[day] + dp[day + 1][false] - fee, dp[day + 1][true]);
            dp[day][false] = max(-prices[day] + dp[day + 1][true], dp[day + 1][false]);
        }
        return dp[0][false];
    }
};
