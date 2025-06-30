// Time complexity O(Log10n)
// Space complexity O(Log10n)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        if(n == 1) return true;

        while(!seen.contains(n)){
            seen.insert(n);
            int newn = 0;
            while(n > 0){
                newn +=  pow(n % 10,2);
                n /= 10;
            }
            if(newn == 1) return true;
            n = newn;
        }
        return false;
    }
};
