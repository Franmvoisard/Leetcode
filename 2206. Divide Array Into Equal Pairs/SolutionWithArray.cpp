class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int frequencyArray[501] = {0};

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(frequencyArray[num] == 1){
                frequencyArray[num]--;
            }
            else {
                frequencyArray[num]++;
            }
        }
        int result = accumulate(frequencyArray, frequencyArray + 501, 0);
        return result == 0;
    }
};
