class Solution {
// Time O(n)
// Space O(n)
public:
    int rob(vector<int>& nums) {
        cache = vector<int>(nums.size(), -1);
        return robHouse(0, nums);
    }

private:
    vector<int> cache;

    int robHouse(int index, vector<int>& houses){
        if(index >= houses.size()) return 0;
        if(cache[index] != -1) return cache[index];

        int robCurrent = houses[index] + robHouse(index + 2, houses);
        int skipCurrent = robHouse(index + 1, houses);
        int result = max(robCurrent, skipCurrent);
        cache[index] = result;
        return result;   
    }
};
