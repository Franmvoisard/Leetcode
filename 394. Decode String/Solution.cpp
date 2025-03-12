class Solution {
public:
    string decodeString(string s) {
        stack<char> charstack;
        string result= "";

        for(int i = 0; i < s.size(); i++){
            char currentChar = s[i];
            if(currentChar != ']'){
                charstack.push(currentChar);
            }
            else {
                string content = "";
                string factor = "";

                while(charstack.top() != '['){
                    content = charstack.top() + content;
                    charstack.pop();
                }

                charstack.pop();

                while(!charstack.empty() && isdigit(charstack.top())){
                    factor = charstack.top() + factor;
                    charstack.pop();
                }

                int multiplier = stoi(factor);
                for(int i = 0; i < multiplier; i++){
                    for(int j = 0; j < content.size(); j++){
                        charstack.push(content[j]);
                    }
                }
            }
        }

        while(!charstack.empty()){
            result = charstack.top() + result;
            charstack.pop();
        }

        return result;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
};
