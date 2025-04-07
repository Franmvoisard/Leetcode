class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        // Time: O(Log(max(a,b,c))
        // Space: O(1)
        while(a || b || c){
            if(c&1){
                if(((a&1) == 0) && ((b&1) == 0)){
                    flips++;
                }
            }
            else {
                flips += (a&1);
                flips += (b&1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};
