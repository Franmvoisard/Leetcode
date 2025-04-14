// Time: O (n^3)
// Space: O (1)

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int goodTriplets = 0;
        int n = arr.size();

        for (int i = 0; i < n - 2; i++) {
            for (int k = i + 2; k < n; k++) {
                if (abs(arr[i] - arr[k]) <= c) {
                    for (int j = i + 1; j < k; j++) {
                        if (abs(arr[i] - arr[j]) <= a &&
                            abs(arr[j] - arr[k]) <= b)
                            goodTriplets++;
                    }
                }
            }
        }
        return goodTriplets;
    }
};
