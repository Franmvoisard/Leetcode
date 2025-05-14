// Time Complexity: O(logn) - O(1) in practice because of Lookup tables
// Space Complexity: O(1)

class Solution {
public:
    int numberOfSteps(int num) {
      if(num == 0) return 0;
      return (int)log2(num) + __builtin_popcount(num);
    }
};
