
class Solution {
//Time O(nlogn) sorting dominates nlogk of heap
//Space O(n + k)

private:
    struct DescendingBySecond {
        bool operator()(const std::pair<int, int>& a,
                        const std::pair<int, int>& b) const {
            return a.second > b.second;
        }
    };

    void orderPairsInDescendingOrder(vector<pair<int, int>>& pairVector,
                                     const vector<int>& pairLefts,
                                     const vector<int>& pairRights) {
        // Create pairs
        for (int i = 0; i < pairLefts.size(); i++) {
            pairVector[i] = {pairLefts[i], pairRights[i]};
        }
        // Sort them by second in desc order
        std::sort(pairVector.begin(), pairVector.end(), DescendingBySecond());
    };

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        vector<pair<int, int>> sortedPairs(nums1.size());
        long long n1sum = 0;
        long long res = 0;

        orderPairsInDescendingOrder(sortedPairs, nums1, nums2);

        for (auto& [n1, n2] : sortedPairs) {
            n1sum += n1;
            minHeap.push(n1);

            if (minHeap.size() > k) {
                n1sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                res = max(res, n1sum * n2);
            }
        }
        return res;
    }
};
