// Time: O (n * m) * log(n * m)
// Space: O (n * m)
class Solution {
private:
    // Possible directions to move: up, down, left, right
    vector<pair<int, int>> directions = {
        {-1, 0}, // Up
        {1, 0},  // Down
        {0, 1},  // Right
        {0, -1}  // Left
    };

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Min-heap to explore paths with the smallest current effort first
        using State = pair<int, pair<int, int>>; // (effort, (row, col))
        priority_queue<State, vector<State>, greater<State>> minHeap;

        // Stores the minimum effort required to reach each cell
        vector<vector<int>> effortTo(rows, vector<int>(cols, INT_MAX));
        effortTo[0][0] = 0;
        minHeap.push({0, {0, 0}}); // Start from the top-left cell

        while (!minHeap.empty()) {
            auto [currEffort, position] = minHeap.top();
            minHeap.pop();
            auto [row, col] = position;

            // Early exit if we've reached the bottom-right cell
            if (row == rows - 1 && col == cols - 1)
                return currEffort;

            // Explore all valid neighbors
            for (auto [dRow, dCol] : directions) {
                int newRow = row + dRow;
                int newCol = col + dCol;

                // Skip out-of-bounds neighbors
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                    continue;

                // Effort for this step = absolute height difference
                int stepEffort = abs(heights[newRow][newCol] - heights[row][col]);

                // Total effort is max of current path effort and this step
                int totalEffort = max(currEffort, stepEffort);

                // If this path is better, update and continue exploring
                if (totalEffort < effortTo[newRow][newCol]) {
                    effortTo[newRow][newCol] = totalEffort;
                    minHeap.push({totalEffort, {newRow, newCol}});
                }
            }
        }

        // Shouldn't reach here in valid input
        return -1;
    }
};
