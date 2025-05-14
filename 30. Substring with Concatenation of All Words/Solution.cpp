// Time complexity: O(n * k)
// Space Complexity: O(n + k)
class Solution {
public:
    unordered_map<string, int> wordFrequency;

    vector<int> findSubstring(string s, vector<string>& words) {
        int wordSize = words[0].size();
        vector<int> result;
        
        if(wordSize > s.size()) return {};
        //Initialize frequency map
        for(auto word : words){
            wordFrequency[word]++;
        }
        
        //We will check every possible offset
        for(int offset = 0; offset < wordSize; offset++){
            unordered_map<string, int> foundWords;
            int totalWordsFound = 0;

            //Loop through each word
            for(int word = offset; word <= s.size() - wordSize; word += wordSize){
                string currentWord = s.substr(word, wordSize);
                
                //Word is not in the list
                if (wordFrequency.count(currentWord) == 0){
                    foundWords.clear();
                    totalWordsFound = 0;
                    continue;
                }
                else { 
                    foundWords[currentWord]++;
                    totalWordsFound++;
                }
                while(foundWords[currentWord] > wordFrequency[currentWord]){
                    //Remove first found word
                    int startingIndexForWordToRemove = word - (totalWordsFound - 1) * wordSize;
                    string wordToRemove = s.substr(startingIndexForWordToRemove, wordSize);
                    foundWords[wordToRemove]--;
                    totalWordsFound--;
                }
             
                if(totalWordsFound == words.size()){
                    result.push_back(word - wordSize * (totalWordsFound - 1));
                }    

            }
        }
        return result;
    }
};
