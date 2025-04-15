class Solution {

//Top down approach with memoization
// Time: O (N * 3 * 2)
// Space: O (N * 3 * 2)

public:
    vector<vector<vector<int>>> memo;

    int dp(int day, int transactionsLeft, int holding, vector<int>& prices){
        int result = 0;

        // Base cases
        if(day == prices.size() || transactionsLeft == 0){
            return 0;
        }
        int cachedResult = memo[day][transactionsLeft][holding];
        if(cachedResult != -1) return cachedResult;

        if(holding){
            int sell = prices[day] + dp(day + 1, transactionsLeft - 1, false, prices);
            int hold = dp(day + 1, transactionsLeft, true, prices);
            result = max(sell, hold);
        }
        else {
            int buy = -prices[day] + dp(day + 1, transactionsLeft, true, prices);
            int hold = dp(day + 1, transactionsLeft, false, prices);
            result = max(buy, hold);
        }

        memo[day][transactionsLeft][holding] = result;
        return result;
    }

    int maxProfit(vector<int>& prices) {
        memo = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        return dp(0, 2 , false, prices);
    }
};
