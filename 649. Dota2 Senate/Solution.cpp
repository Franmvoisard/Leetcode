class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> radiants;
        deque<int> dire;
        int n = senate.size();
        
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R'){
                radiants.push_front(i);
            }
            else {
                dire.push_front(i);
            }
        }

        while(!radiants.empty() && !dire.empty()){
            int rad = radiants.back();
            int dir = dire.back();

            if(rad < dir){
                dire.pop_back();
                radiants.push_front(dir + n);
                radiants.pop_back();
            }
            else {
                radiants.pop_back();
                dire.push_front(rad + n);
                dire.pop_back();
            }
        }
        
        return !radiants.empty() ? "Radiant" : "Dire";
    }
};
