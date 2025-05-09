// Time complexity: O(N + E * log N)
// Space complexity: O(N + E)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using State = pair<double, int>;
        using Node = pair<int,double>;
        vector<vector<Node>> adjacencyList(n); // E * V space
        priority_queue<State, vector<State>, less<State>> maxHeap;
        vector<double> probabilities(n, 0.0);
        vector<bool> visited(n, false);

        // Build adjacency list
        for(int i = 0; i < edges.size(); i++){ 
            int nodeId = edges[i][0];
            double successProbability = succProb[i];
            int destinationNode = edges[i][1];
            adjacencyList[nodeId].emplace_back(destinationNode, successProbability);
            adjacencyList[destinationNode].emplace_back(nodeId, successProbability);
        }

        // Initialize PQ And distance vector
        probabilities[start_node] = 1;
        maxHeap.push(State(1.0, start_node)); //O(log E+V)

        // Dijsktra loop

        while(!maxHeap.empty()){
            auto [probability, nodeId] = maxHeap.top(); // O(1) 
            maxHeap.pop();
            if(visited[nodeId]) continue;
            visited[nodeId] = true;
            if (nodeId == end_node) return probability;

            for(auto [neighborId, neighborProbability] : adjacencyList[nodeId]){
                double newProbability = probability * neighborProbability;
                if(probabilities[neighborId] <= newProbability){
                    probabilities[neighborId] = newProbability;
                    maxHeap.push(State(newProbability, neighborId));
                }
            }
        }

        return probabilities[end_node] == -1.0 ? 0 : probabilities[end_node];
    }
};
