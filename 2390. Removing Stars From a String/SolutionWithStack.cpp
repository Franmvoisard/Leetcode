#include <algorithm> 
class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        int n = s.size();
        string result = "";

        for(int i = 0; i < n; i++){
            char currentChar = s[i];

            if(currentChar != '*'){
                stack.push(currentChar);
            }
            else {
                stack.pop();
            }
        }

       int i = stack.size();
       while(i > 0){
            result += stack.top();
            stack.pop();
            i--;
        }
       reverse(result.begin(), result.end());
        return result;

    }
};
