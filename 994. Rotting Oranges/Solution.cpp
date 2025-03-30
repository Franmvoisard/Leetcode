class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int time = 0, fresh = 0;
        queue<pair<int, int>> queue;

        static const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) queue.emplace(i, j);
            }
        }

        // BFS traversal
        while (!queue.empty() && fresh > 0) {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                auto [x, y] = queue.front();
                queue.pop();

                for (const auto& [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;

                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        queue.emplace(newX, newY);
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
