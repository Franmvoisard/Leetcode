class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> values;
        int n = nums.size();
        values.reserve(n);

        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(values.find(num) != values.end()){
                return true;
            }
            else{
                values.insert(num);
            }
        }
        return false;
    }
};
