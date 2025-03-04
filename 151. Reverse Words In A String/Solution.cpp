class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = s.size();
        int i = s.size()-1;
        string result = "";
        while(i >= 0){
            while(i >= 0 && s[i] == ' '){ //Ignore spaces
                i--;
            }
            if(i < 0) break;

            lastSpaceIndex = i;

            while(i >= 0 && s[i] != ' '){
                i--;
            }

            if(result.empty()){
                result = s.substr(i+1, lastSpaceIndex - i);
            }
            else {
                 result += " " + s.substr(i+1, lastSpaceIndex - i);
            }
        }
    return result;
    }
};
