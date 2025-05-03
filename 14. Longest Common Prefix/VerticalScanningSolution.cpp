// Time: O(n * m), n is the number of strings and m is the shortest string in the array.
// Space: O(m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs[0].size(); i++){
            char character = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j].size() < i || strs[j][i] != character) {
                    return result;
                }
            }
            result += character;
        }
        return result;
    }
};
