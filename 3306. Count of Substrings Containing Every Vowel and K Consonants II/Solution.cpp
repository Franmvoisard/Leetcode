class Solution {
private:
    static inline bool isVowel(char c) {
        return c == 'a' ||
               c == 'e' ||
               c == 'i' ||
               c == 'o' ||
               c == 'u';
    }

    static inline long long solve(string& word, int k) {
        unordered_map<char, int> frequencies;
        int consonantCount = 0;
        long long result = 0;

        // Sliding window pointers
        int left = 0;

        for (int right = 0; right < word.size(); right++){
            char currentCharacter = word[right];

            if(isVowel(currentCharacter)){
                frequencies[currentCharacter]++;
            }
            else {
                consonantCount++;
            }

            while(frequencies.size() == 5 && consonantCount >= k){
                cout << "Current char= " << currentCharacter << " " << word.substr(left, (right + 1 - left)) << " " << right-left + 1 << endl;
                cout << "result += " << word.size() << " - " << right << " (" << (word.size() - right) << ")" << endl;
                result += word.size() - right;
                cout << "result = " << result << endl;
                char characterToRemove = word[left];

                if(isVowel(characterToRemove)){
                    frequencies[characterToRemove]--;
                    if(frequencies[characterToRemove] == 0){
                        frequencies.erase(characterToRemove);
                    }
                }
                else {
                    consonantCount--;
                }
                left++;
            }
        }
        return result;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }
};

static auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return nullptr;
}();
