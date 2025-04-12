class Solution {
    // Time: O(n)
    // Space: O(n)
private:
    unordered_map<int, int> cache = {{0, 0}, {1, 1}, {2, 1}};

public:
    int tribonacci(int n) {
        if (cache.contains(n))
            return cache[n];

        cache[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return cache[n];
    }
};
