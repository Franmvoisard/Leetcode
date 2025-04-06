class Solution {
public:
    // Time: O(kLogc)
    // Space: O(Candidates)

    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, std::greater<int>> left_minHeap;
        priority_queue<int, vector<int>, std::greater<int>> right_minHeap;

        int left = 0;
        int right = costs.size() - 1;
        long long minCost = 0;

        for(int i = 0; i < candidates && left <= right; i++){
            left_minHeap.push(costs[left]); 
            left++;
        }

        for(int i = 0; i < candidates && left <= right; i++){ 
            right_minHeap.push(costs[right]); 
            right--;
        }
        
        for(int i = 0; i < k; i++){
            int minLeft = left_minHeap.empty() ? INT_MAX : left_minHeap.top();
            int minRight = right_minHeap.empty() ? INT_MAX : right_minHeap.top();

            if(minLeft <= minRight){
                minCost += minLeft;
                left_minHeap.pop();
               
                if(left <= right){
                    left_minHeap.push(costs[left]);
                    left++;
                }
            }
            else {
                minCost += minRight;
                right_minHeap.pop();
                if(left <= right){
                    right_minHeap.push(costs[right]);
                    right--;
                }
            }
        }
      
        return minCost;
    }
};
