class Solution {
public:
    // Time: O(log10 n)
    // Space O(1)
    bool isPalindrome(int x) {
        if(x < 0 || x % 10 == 0 && x != 0) return false;
        if(x < 10) return true;

        int reversedHalf = 0;
        while (x > reversedHalf){
            reversedHalf = reversedHalf * 10 + x % 10; //Append to the reversed half
            x /= 10;
        }

        return reversedHalf == x || reversedHalf / 10 == x;
    }
};
