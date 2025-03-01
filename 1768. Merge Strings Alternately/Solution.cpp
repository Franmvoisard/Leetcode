class Solution {

public:
   string mergeAlternately(string word1, string word2) {
        string result;
        int n = max(word1.size(), word2.size());
   
        for(int i = 0; i < n; i++) {
            if(word1.size() > i){
                result.push_back(word1[i]);
            }
            if(word2.size() > i){
                result.push_back(word2[i]);
            }
        }
        return result;
    }
};
