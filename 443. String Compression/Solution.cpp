class Solution {
public:
    int compress(vector<char>& chars) {
        int currentLetterIndex = 0;
        int currentElementIndex = 0;
        int lastCharacterCompressed = 0;
        
        while(currentLetterIndex < chars.size()){
            while(currentElementIndex < chars.size() && chars[currentElementIndex] == chars[currentLetterIndex]){
                currentElementIndex++;
            }
            int repetitions = currentElementIndex - currentLetterIndex;
            if(repetitions == 1){
                chars[lastCharacterCompressed] = chars[currentLetterIndex];
                lastCharacterCompressed++;
            }
            else {
                chars[lastCharacterCompressed] = chars[currentLetterIndex];
                lastCharacterCompressed++;
                string repetitionsString = to_string(repetitions);
                for(int i = 0; i < repetitionsString.size(); i++){
                    chars[lastCharacterCompressed] = repetitionsString[i];
                    lastCharacterCompressed++;
                }
             }
             currentLetterIndex = currentElementIndex;
        }
        return lastCharacterCompressed;
    }
};
