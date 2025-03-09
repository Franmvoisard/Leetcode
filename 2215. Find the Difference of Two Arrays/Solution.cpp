class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> response(2);
        unordered_set<int> numsOneSet(nums1.begin(), nums1.end());
        unordered_set<int> numsTwoSet(nums2.begin(), nums2.end());
        
        for(auto number : numsOneSet){
            if(numsTwoSet.count(number) == 0){
                response[0].push_back(number);
            }
        }
        
        for(auto number : numsTwoSet){
            if(numsOneSet.count(number) == 0){
                response[1].push_back(number);
            }
        }
        return response;
    }
};
