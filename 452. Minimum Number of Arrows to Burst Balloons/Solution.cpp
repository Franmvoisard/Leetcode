// Time: O nlogn due to sorting
// Space: O (1)
class Solution {

    static bool sortBallonsByEndX(const vector<int>& left, const vector<int>& right){
        return left[1] < right[1];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int result = 1;
        sort(points.begin(), points.end(), sortBallonsByEndX);
        
        int lowerXEnd = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= lowerXEnd) continue;
            else {
                result++;
                lowerXEnd = points[i][1];
            }
        }
        return result;
    }
};
