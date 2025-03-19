class Solution {
private:
    bool isSuccessful(int potion, int spell, long long success){
        return 1LL * potion * spell >= success;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int spellsSize = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> answer(spellsSize);

        for(int i = 0; i < spellsSize; i++){
            int left = 0;
            int right = potions.size();

            while(left < right){
                int midpoint = left + (right - left) / 2;
                long long currentPotion = potions[midpoint];
                if(isSuccessful(currentPotion, spells[i], success)){ // We can keep trying to shrink
                    right = midpoint;
                }
                else{
                    left = midpoint + 1;
                }
            }
            answer[i] = potions.size() - left;
        }
        return answer;
    }
};
