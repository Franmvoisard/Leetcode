// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        
        if(totalGas < totalCost) return -1;

        int n = gas.size();
        int result = 0;
        int accumulated = 0;

        for(int i = 0; i < n; i++){
            accumulated += gas[i] - cost[i];
            if(accumulated < 0){
                result = i + 1;
                accumulated = 0;
            }
        }
        return result;
    }
};
