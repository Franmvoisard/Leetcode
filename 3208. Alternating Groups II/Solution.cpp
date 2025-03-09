class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
      
        int n = colors.size();
        int alternateColorCount = 1;
        int previousColor = colors[0];
        int totalIterations = n + k - 1;
        int groupsCount = 0;

        for(int i = 1; i < totalIterations; i++){
            
            int currentColor = colors[i % n];
            if(previousColor == currentColor){
                alternateColorCount = 1;
            }
            else{
                alternateColorCount++;
                if(alternateColorCount >= k){
                    groupsCount++;
                }
                previousColor = currentColor;
            }
        }
        return groupsCount;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
