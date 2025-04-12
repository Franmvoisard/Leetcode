class Solution {
    // Time: O(n)
    // Space: O(n)
public:
    int tribonacci(int n) {
        vector<int> cache(n + 3, 0);
        cache[1] = cache[2] = 1;

        for(int i = 3; i <= n; i++){
            cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
        }

        return cache[n];
    }
};
