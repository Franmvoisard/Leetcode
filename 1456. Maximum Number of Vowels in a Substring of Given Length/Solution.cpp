class Solution {

private:
    bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
};

public:
    int maxVowels(string s, int k) {
        int maxNumberOfVowels = 0;
        int inputSize = s.size();
        int currentWindowVowels = 0;

        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) currentWindowVowels++;
        }

        maxNumberOfVowels = currentWindowVowels;

        for(int i = k; i < inputSize; i++){
            if(isVowel(s[i-k])){
                currentWindowVowels--;
            }

            if(isVowel(s[i])){
                currentWindowVowels++;
            }

            maxNumberOfVowels = max(currentWindowVowels, maxNumberOfVowels);
            if(maxNumberOfVowels == k) break;
            
        }
        return maxNumberOfVowels;
    }
};
