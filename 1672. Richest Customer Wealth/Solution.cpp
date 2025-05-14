// Time complexity: O(accounts * banks)
// Space complexity: O(1)

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int banks = accounts[0].size();
        int maximumWealth = 0; 
        for(int customer = 0; customer < accounts.size(); customer++){
            int wealth = 0;
            for(int account = 0; account < banks; account++){
                wealth += accounts[customer][account];
            }
            maximumWealth = max(maximumWealth, wealth);
        }
        return maximumWealth;
    }
};
