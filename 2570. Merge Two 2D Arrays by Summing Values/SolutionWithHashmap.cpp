class Solution {

public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> arraysum;
        vector<vector<int>> result;

        for(const auto& pair : nums1){
            arraysum[pair[0]] += pair[1];
        }

        for(const auto& pair : nums2){
            arraysum[pair[0]] += pair[1];
        }

        for(auto& it : arraysum){
            result.push_back({it.first, it.second});
        }
        return result;
    }
};
