class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int lengthA =  str1.size();
        int lengthB =  str2.size();

        while(lengthB != 0){
            int temp = lengthA % lengthB;
            lengthA = lengthB;
            lengthB = temp;
        }
        return str1.substr(0, lengthA);
    }
};
