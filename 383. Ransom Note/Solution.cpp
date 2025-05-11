// Time Complexity: O(n)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> availableLetters(26, 0);

        for (int i = 0; i < magazine.size(); i++) {
            availableLetters[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            int currentCharacter = ransomNote[i] - 'a';

            if (availableLetters[currentCharacter] == 0)
                return false;
            else {
                availableLetters[currentCharacter]--;
            }
        }
        return true;
    }
};
