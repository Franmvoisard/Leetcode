// Time complexity O(N)
// Space complexity O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while(left < right){
            int leftHeight = height[left];
            int rightHeight = height[right];
            int water = min(rightHeight, leftHeight) * (right - left);
            maxWater = max(maxWater, water);
            if(leftHeight < rightHeight){
                left++;
            }
            else right--;
        }
        return maxWater;
    }
};
