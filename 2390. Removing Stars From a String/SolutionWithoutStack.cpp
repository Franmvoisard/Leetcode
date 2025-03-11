class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string result = "";
        int starCounter = 0;

        for(int i = n-1; i >= 0; i--){
            char currentChar  = s[i];
            if(currentChar == '*'){
                starCounter++;
            }
            else {
                if(starCounter == 0){
                    result += currentChar;
                }
                else {
                    starCounter--;
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
