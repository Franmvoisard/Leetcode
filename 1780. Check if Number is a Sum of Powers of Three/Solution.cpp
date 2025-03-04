class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0 && n % 3 != 2){
            n /= 3;            
        }
        if(n == 0) return true;
        return false;
    }
};
