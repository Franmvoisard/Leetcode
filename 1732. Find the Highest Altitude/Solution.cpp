class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int highest = 0;
        int currentHeight = 0;
        
        for(int i=0; i < gain.size(); i++){
            currentHeight += gain[i];
            highest = max(highest, currentHeight);
        }
        return highest;
    }
};

