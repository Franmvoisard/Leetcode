class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++){
            int value = nums[i];
            auto it = map.find(value);

            if(it != map.end() && abs(it->second - i) <= k){
                return true;
            }
            else {
                map[value] = i;
            }
        }
        return false;
    }
};
