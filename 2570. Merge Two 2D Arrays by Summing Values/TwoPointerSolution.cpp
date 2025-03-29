class Solution {
private:
    void insertRemainingElements(int& indexPointer, const vector<vector<int>>& array, vector<vector<int>>& resultArray){
        int arraySize = array.size();
        while(indexPointer < arraySize){
            resultArray.push_back({array[indexPointer][0], array[indexPointer][1]});
            indexPointer++;
        }
    }

public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int nums1ptr = 0, nums2ptr = 0;
        vector<vector<int>> result;

        while(nums1ptr < nums1.size() && nums2ptr < nums2.size()){
            int nums1Id = nums1[nums1ptr][0];
            int nums2Id = nums2[nums2ptr][0];

            if(nums1Id == nums2Id){
                result.push_back({nums1Id, nums1[nums1ptr][1] + nums2[nums2ptr][1]});
                nums1ptr++;
                nums2ptr++;
            }
            else if(nums1Id < nums2Id){
                result.push_back({nums1Id, nums1[nums1ptr][1]});
                nums1ptr++;
            }
            else {
                result.push_back({nums2Id, nums2[nums2ptr][1]});
                nums2ptr++;
            }
        }

        insertRemainingElements(nums1ptr, nums1, result);
        insertRemainingElements(nums2ptr, nums2, result);

        return result;
    }
};
