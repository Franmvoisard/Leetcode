// Time: O(n)
// Space: O(n)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result = "";
        for(int i = s.size()-1; i >= 0; i--){    
            while(i >= 0 && s[i] == ' '){
                i--;
            }
          
            int wordEnd = i; 
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            int wordStart = i+1;
            result += s.substr(wordStart, wordEnd - wordStart + 1);

            if(i > 0) result += " ";
        }
        if(!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};
