class Solution {

public:
    vector<vector<vector<int>>> dpTable;
    // Time: O(n)
    // Space: O(n)

    inline void fillDPTable(vector<int>& prices){
        int result = 0;
        int n = prices.size();
        for(int day = n-1; day >= 0; day--){
            for(int transactionsLeft = 2; transactionsLeft > 0; transactionsLeft--){
                //If we hold today, the 2 options are hold (keep transactions and holding) or sell (transitions to transactionsLeft-- and false)
                dpTable[day][transactionsLeft][true] = max(dpTable[day + 1][transactionsLeft][true], prices[day] + dpTable[day + 1][transactionsLeft - 1][false]);

                 //If do not hold stock today, the 2 options are to stay the same (keep transactions and holding state) or buy 
                 // We discount the price stock of buying it and then we pick the maximum value(where holding =false)
                dpTable[day][transactionsLeft][false] = max(dpTable[day + 1][transactionsLeft][false], -prices[day] + dpTable[day + 1][transactionsLeft][true]);
            }
        }
    }

    int maxProfit(vector<int>& prices) {
        dpTable = vector<vector<vector<int>>>(prices.size() + 1, vector<vector<int>>(3, vector<int>(2, 0)));
        fillDPTable(prices);
        return dpTable[0][2][0];
    }
};
