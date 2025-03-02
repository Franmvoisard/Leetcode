class Solution {
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool isVowel(char ch){
        return vowels.find(ch) != vowels.end();
    }

public:
    string reverseVowels(string s) {
        int leftIndex = 0;
        int rightIndex = s.size() - 1;
        
        while(leftIndex < rightIndex){
            char leftIndexChar = s[leftIndex];
            char rightIndexChar = s[rightIndex];

            bool leftIsVowel = isVowel(leftIndexChar);
            bool rightIsVowel = isVowel(rightIndexChar);

            if(leftIsVowel == false){
                leftIndex++;
            }
            else if(rightIsVowel == false){
                rightIndex--;
            }
            else {
                swap(s[leftIndex++], s[rightIndex--]);
            }
        }
        return s;
    }
};
