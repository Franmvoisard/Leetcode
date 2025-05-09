// Time Complexity: O((V + E) * K * log V)
// Space Complexity: O(n * k + E)

class Solution {
    using Node = pair<int, int>; // Represent a flight as a pair of destination and weight (cost)

public:
    struct State {
        int weight;         // Total weight (cost) to reach this node
        int nodeId;         // The current node (city)
        int numOfFlights;   // Number of flights taken to reach this node

        // Constructor for initializing the State
        State(int w, int id, int flights) : weight(w), nodeId(id), numOfFlights(flights) {}

        // Define the comparison for priority queue (min heap)
        bool operator>(const State& other) const {
            return weight > other.weight; // Compare based on the total cost (weight)
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list to store the flights, where each city has a list of (destination, cost)
        vector<vector<Node>> adjacencyList(n);

        // Distance table where distance[node][numOfFlights] stores the minimum cost to reach the 'node'
        // with 'numOfFlights' taken. Initialize with a high value (INT_MAX).
        vector<vector<int>> distance(n, vector<int>(k + 2, INT_MAX));

        // Min-heap to explore the node with the least cost first
        priority_queue<State, vector<State>, greater<State>> minHeap;

        // Build the adjacency list from the flight data
        for (const auto& flight : flights) {
            int origin = flight[0];
            int destination = flight[1];
            int cost = flight[2];

            adjacencyList[origin].push_back({destination, cost});
        }

        // Initialize the min heap by pushing the source city with 0 cost and 0 flights taken
        minHeap.push(State(0, src, 0));
        distance[src][0] = 0; // The cost to reach the source with 0 flights is 0

        while (!minHeap.empty()) {
            // Extract the state with the least cost from the min-heap
            auto [currentWeight, currentNode, currentNumFlights] = minHeap.top();
            minHeap.pop();

            // If we've reached the destination, return the current cost (no need to continue)
            if (currentNode == dst) return currentWeight;

            // If the number of flights exceeds k, skip this state (we can't take more than k flights)
            if (currentNumFlights > k) continue;

            // Explore the neighbors (possible next flights) of the current node
            for (const auto& [neighborId, neighborCost] : adjacencyList[currentNode]) {
                int newWeight = currentWeight + neighborCost; // Calculate the new weight (cost) to reach the neighbor

                // If the new cost is cheaper than the previously recorded cost for this neighbor with the next flight count
                if (newWeight < distance[neighborId][currentNumFlights + 1]) {
                    // Update the cost for the neighbor and push the new state to the min-heap
                    distance[neighborId][currentNumFlights + 1] = newWeight;
                    minHeap.push(State(newWeight, neighborId, currentNumFlights + 1));
                }
            }
        }
        // If no valid path was found, return -1
        return -1;
    }
};
