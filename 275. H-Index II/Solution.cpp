// Time: O (log n)
// Space: O (1)
class Solution {
    private:
    int binary_search(const vector<int>& citations){
        int n = citations.size();
        int left = 0;
        int right = n - 1;

        while(left <= right){
            int m = left + (right - left) / 2;
            if(citations[m] >= n - m){
                right = m - 1;
            }
            else {
                left = m + 1;
            }
        }
        return n - left;
    }
public:
    int hIndex(vector<int>& citations) {
      return binary_search(citations);  
    }
};
