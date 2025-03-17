class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> frequencySet;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(frequencySet.contains(num)){
                frequencySet.erase(num);
            }
            else {
                frequencySet.insert(num);
            }
        }

        return frequencySet.empty();
    }
};
