class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long) *min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long timeToRepair = 0;

        while(left <= right){
            long long midpoint = left + (right-left) / 2;
            long long carsThatCanBeRepaired = 0;

            for(int i = 0; i < ranks.size(); i++){
                carsThatCanBeRepaired += sqrt(midpoint / ranks[i]);
            }

            if(carsThatCanBeRepaired >= cars){
                timeToRepair = midpoint;
                right = midpoint - 1;
            }
            else {
                left = midpoint + 1;
            }
        }
        return timeToRepair;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
};
