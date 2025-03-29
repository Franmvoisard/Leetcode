class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lessIndex = 0;
        int greaterIndex = nums.size() - 1; ;
        vector<int> answer(nums.size());
        int left = 0;
        int right = nums.size() - 1;

        while(left < nums.size()){
            if(nums[left] < pivot){
                answer[lessIndex] = nums[left];
                lessIndex++;
            }
            if(nums[right] > pivot){
                answer[greaterIndex] = nums[right];
                greaterIndex--;
            }
            left++;
            right--;
        }
        
        while(lessIndex <= greaterIndex){
            answer[lessIndex] = pivot;
            lessIndex++;
        }
        return answer;
    }
};
