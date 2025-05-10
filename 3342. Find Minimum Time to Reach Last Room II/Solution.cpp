//Time complexity O (N + E + log N)
//Space complexity O (N + E)

class Solution {
private:
    vector<pair<int, int>> directions = {
        {-1, 0}, // L
        {1, 0},  // R
        {0, -1}, // U
        {0, 1},  // D
    };

public:
    struct State {
    public:
        int x;
        int y;
        int time;
        State(int x, int y, int time) : x(x), y(y), time(time) {};

        bool operator>(const State& other) const { return time > other.time; }
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();    // Rows
        int m = moveTime[0].size(); // Columns

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        priority_queue<State, vector<State>, std::greater<State>> minHeap;
        
        distance[0][0] = 0;
        minHeap.push(State(0, 0, 0));

        while (!minHeap.empty()) {
            State curNode = minHeap.top();
            minHeap.pop();

            // Early exit when the destination is reached
            if (curNode.x == n - 1 && curNode.y == m - 1) {
                break;
            }

            // Add neighbors
            for (auto [dirX, dirY] : directions) {
                int nextX = curNode.x + dirX;
                int nextY = curNode.y + dirY;
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) { // Is invalid
                    continue;
                }

                // Calculate the wait time
                int additionalTime = (curNode.x + curNode.y) % 2 + 1;
                int waitTime = max(distance[curNode.x][curNode.y], moveTime[nextX][nextY]) + additionalTime;

                if (waitTime < distance[nextX][nextY]) {
                    distance[nextX][nextY] = waitTime;
                    minHeap.push(State(nextX, nextY, waitTime));
                }
            }
        }

        return distance[n - 1][m - 1];
    }
};
