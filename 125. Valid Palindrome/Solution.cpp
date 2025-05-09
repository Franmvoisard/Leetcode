// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            char leftChar = tolower(s[left]);
            char rightChar = tolower(s[right]);

            if (leftChar != rightChar) return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};
