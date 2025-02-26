## Overview

## Url
[https://leetcode.com/problems/remove-duplicates-from-sorted-array/](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
## Time Complexity 
 > O(n) - single pass.


## Space Complexity
 > O(1) - in-place modifications.

The `removeDuplicates` function in C++ removes duplicate elements from a sorted array in-place and returns the count of unique elements. It maintains the original order and modifies the array efficiently.

## Code Breakdown

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
```

### Insights
- Uses **two pointers** to shift unique elements forward.
- Avoids unnecessary swaps, making it **efficient**.
