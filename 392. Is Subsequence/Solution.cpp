class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;

        int i = 0;
        int nextLetterIndex = 0;;

        while(i < t.size()){
            if(nextLetterIndex <= s.size() && t[i] == s[nextLetterIndex]){
                nextLetterIndex++;
                if(nextLetterIndex == s.size()) break;
            }
            i++;
        }
        return nextLetterIndex == s.size();
    }
};
