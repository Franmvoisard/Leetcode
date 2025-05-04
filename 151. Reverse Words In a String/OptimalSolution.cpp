// Time: O(n)
// Space: O(1)

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int write = 0;

        for (int i = 0; i < n; i++) {
            // Skip whitespaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            if (i >= n) {
                break;
            }

            // Add whitespace to write pointer if not the first word
            if (write != 0) {
                s[write] = ' ';
                write++;
            }

            // Read new word and append it to the write pointer position of the already scanned positions
            int wordStart = i;
            int wordLength = 0;
            while (i < n && s[i] != ' ') {
                s[write] = s[i];
                i++;
                write++;
                wordLength++;
            }

            // Reverse the word range to leave the word in the correct order.
            reverse(s.begin() + write - wordLength, s.begin() + write);
        }

        //Resize to the size of j
        s.resize(write);
        return s;
    }
};
