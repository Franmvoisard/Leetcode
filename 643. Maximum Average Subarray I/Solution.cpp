class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maximumSum = INT_MIN;
        double currentWindowSum = 0;

        for(int i = 0; i < k; i++){
            currentWindowSum += nums[i];
        }
        maximumSum = currentWindowSum;

        for(int i = k; i < nums.size(); i++){
            currentWindowSum -= nums[i-k];
            currentWindowSum += nums[i];
    
            if(currentWindowSum > maximumSum){
                maximumSum = currentWindowSum;
            }
        }
        return maximumSum / k;
    }
};
