class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxWaterCapacity = 0;

        while(left < right){

            int diff = right - left;
            int lowerHeight = min(height[left], height[right]);
            if(height[left] <=  height[right]){
                left++;
            }
            else {
                right--;
            }

            maxWaterCapacity = max(maxWaterCapacity, lowerHeight * diff);
        }
        return maxWaterCapacity;
    }
};
