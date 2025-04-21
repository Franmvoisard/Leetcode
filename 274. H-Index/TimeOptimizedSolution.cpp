// Time : O(n)
// Space : O(n)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> citationBuckets(n + 1, 0);

        for (int citation : citations) {
            citationBuckets[min(citation, n)]++;
        }

        int cumPapers = 0;
        for (int i = n; i >= 0; i--) {
            cumPapers += citationBuckets[i];
            if (cumPapers >= i)
                return i;
        }

        return 0;
    }
};
