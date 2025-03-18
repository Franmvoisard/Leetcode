class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int current = 0;
        int left = 0;
        int answer = 0;
        
        for (int right = 0; right < nums.size(); right++){
            while((current & nums[right]) != 0){
                current = current ^ nums[left]; //Substract left  from bitmask
                left++;
            }

            current = current | nums[right]; // Add to bitmask
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};
