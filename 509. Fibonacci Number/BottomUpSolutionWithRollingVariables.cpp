// Time: O(n)
// Space: O(1)
class Solution {

public:
    int previousMin1 = 1;
    int previousMin2 = 0;

    int fib(int n) {
        if(n < 2) return n;
        int res = 0;
        for(int i = 2; i <= n; i++){
            res = previousMin1 + previousMin2;
            previousMin2 = previousMin1;
            previousMin1 = res;
        }
        return res; // 1 1 2 3 5
    }
};
