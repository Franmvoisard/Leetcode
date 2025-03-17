class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        if(nums.size() % 2 != 0) return false;

        for(int i = 0; i < nums.size(); i++){
            frequencyMap[nums[i]]++;
        }

        for(auto it : frequencyMap){
            if(it.second % 2 != 0) return false;
        }
        return true;
    }
};
