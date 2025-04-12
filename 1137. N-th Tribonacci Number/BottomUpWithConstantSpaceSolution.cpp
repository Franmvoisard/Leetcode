class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int prev1 = 1, prev2 = 1, prev3 = 0;
        int result = 0;
        
        for (int i = 3; i <= n; ++i) {
            result = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = result;
        }
        
        return result;
    }
};
