// Time O(n)
// Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        static const unordered_map<char, int> romanNumbers = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int result = 0;
        int n = s.size();
        int last = romanNumbers.at(s[n-1]);
        result += last;

        for(int i = n-2; i >= 0; i--){
            int current = romanNumbers.at(s[i]);

            if(current < last){ 
                result -= current;
            }
            else {
                result += current;
            }
            last = current;
        }
        return result;
    }
};
