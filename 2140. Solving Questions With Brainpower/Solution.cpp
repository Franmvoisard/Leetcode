class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> cache(n, 0);

        for(int i = n-1; i >= 0; i--){
            int points = questions[i][0];
            int brainPower = questions[i][1];

            int nextIndex = i + brainPower + 1;
            long long choose = points + (nextIndex >= n ? 0 : cache[nextIndex]); 
            long long skip = i + 1 >= n ? 0 : cache[i + 1];
            cache[i] = max(choose, skip);
        }
        return cache[0];
    }
};
