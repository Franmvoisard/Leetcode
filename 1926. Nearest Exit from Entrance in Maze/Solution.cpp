class Solution {
private:
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // left, right, down, up
    
    bool isExit(const pair<int, int>& current,
                const pair<int, int>& boundaries,
                const pair<int, int>& entrance) {
        int x = current.first, y = current.second;
        return (x == 0 || y == 0 || x == boundaries.first - 1 || y == boundaries.second - 1) &&
               !(x == entrance.first && y == entrance.second);
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int stepsCount = 0;
        int rows = maze.size(), cols = maze[0].size();
        pair<int, int> boundaries = {rows, cols};
        queue<pair<int, int>> queue;
        queue.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        while (!queue.empty()) {
            int qSize = queue.size();
            stepsCount++;
            for (int i = 0; i < qSize; i++) {
                auto [x, y] = queue.front();
                queue.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && maze[nx][ny] == '.') {
                        if (isExit({nx, ny}, boundaries, {entrance[0], entrance[1]})) {
                            return stepsCount;
                        }
                        queue.push({nx, ny});
                        maze[nx][ny] = '+';
                    }
                }
            }
        }
        return -1;
    }
};
