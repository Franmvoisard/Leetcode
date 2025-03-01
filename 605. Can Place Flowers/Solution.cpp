class Solution {

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        for(int i = 0; i < flowerbed.size();i++){
            if(flowerbed[i] == 0){
                bool isLeftAvailable = i == 0 || flowerbed[i-1] == 0;
                bool isRightAvailable = i == flowerbed.size()-1 || flowerbed[i+1] == 0;
                if(isLeftAvailable && isRightAvailable){
                    flowerbed[i] = 1;
                    n--;
                    i++;
                    if(n == 0) return true;
                }
            } 
        }
        return false;
    }
};
