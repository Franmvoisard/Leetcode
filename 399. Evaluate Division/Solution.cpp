class Solution {
    using adjacency_list = unordered_map<string, vector<pair<string, double>>>;

private:
    adjacency_list buildAdjacencyList(const vector<vector<string>>& equations, const vector<double>& values) {
        adjacency_list adjacencies;
        for (size_t i = 0; i < equations.size(); i++) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double value = values[i];

            adjacencies[A].emplace_back(B, value);
            adjacencies[B].emplace_back(A, 1.0 / value);
        }
        return adjacencies;
    }

    double bfs(adjacency_list& adjacencies, const string& start, const string& target) {
        if (!adjacencies.count(start) || !adjacencies.count(target)) return -1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;
        
        q.emplace(start, 1.0);
        visited.insert(start);

        while (!q.empty()) {
            auto [current, weight] = q.front();
            q.pop();

            if (current == target) return weight;

            for (const auto& [neighbor, edgeWeight] : adjacencies[current]) {
                if (!visited.count(neighbor)) {
                    q.emplace(neighbor, weight * edgeWeight);
                    visited.insert(neighbor);
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        adjacency_list adjacencies = buildAdjacencyList(equations, values);
        vector<double> result;
        result.reserve(queries.size());

        for (const auto& query : queries) {
            result.push_back(bfs(adjacencies, query[0], query[1]));
        }
        return result;
    }
};
