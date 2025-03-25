class Solution {
private:
    inline int countNonOverlappingIntervals(const vector<pair<int, int>>& intervals) {
        int count = 0;
        int lastIntervalEnd = -1;

        for (const auto& [start, end] : intervals) { 
            if (lastIntervalEnd <= start) { 
                count++;
                if (count >= 3) return 3;
                lastIntervalEnd = end;  
            } else {
                lastIntervalEnd = max(lastIntervalEnd, end);  // Merge overlapping intervals
            }
        }
        return count;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int inputSize = rectangles.size();
        vector<pair<int, int>> xIntervals;
        vector<pair<int, int>> yIntervals;
        xIntervals.reserve(inputSize);
        yIntervals.reserve(inputSize);

        for (const auto& rect : rectangles) {
            xIntervals.emplace_back(rect[0], rect[2]);
            yIntervals.emplace_back(rect[1], rect[3]);
        }

        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        };

        sort(xIntervals.begin(), xIntervals.end(), comparator);
        sort(yIntervals.begin(), yIntervals.end(), comparator);

        if (countNonOverlappingIntervals(xIntervals) >= 3) return true;
        return countNonOverlappingIntervals(yIntervals) >= 3;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
