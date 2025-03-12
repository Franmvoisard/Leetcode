class Solution {
    private:
    int findUpperBound(vector<int>& vector){
        int left = 0;
        int right = vector.size() - 1;
        int index = vector.size();

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(vector[mid] <= 0){
                left =  mid + 1;
            }
            else {
                right = mid - 1;
                index = mid;
            }
        }
        return index;
     }
     int findLowerBound(vector<int>& vector){
        int left = 0;
        int right = vector.size() -1;
        int index = vector.size();

        while(left <= right){
            int mid = left + (right-left) / 2;
            if(vector[mid] < 0){
                left =  mid + 1;
            }
            else {
                right = mid - 1;
                index = mid;
            }
        }
        return index;
     }
public:
    int maximumCount(vector<int>& nums) {
        int positiveCount = nums.size() - findUpperBound(nums);
        int negativeCount = findLowerBound(nums);
        return max(positiveCount, negativeCount);
    }
};
