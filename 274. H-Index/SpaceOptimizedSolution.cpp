// Time: O(nlogn) 
// Space: O(1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); 

        for (int i = n - 1; i >= 0; --i) {
            int papers = n - i;
            if (citations[i] < papers) {
                return papers - 1;
            }
        }

        return n;
    }
};
