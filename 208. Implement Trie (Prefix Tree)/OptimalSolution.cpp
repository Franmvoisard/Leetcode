class Solution {
public:
    // P # of products, W word length
    // Time: O(Plog(P)) + O(W * log(P))) Sorting + Binary search searchWord.size() times
    // Space O (W)

    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, bsStart = 0, n=products.size();
        string prefix;
        
        for (char &c : searchWord) {
            prefix += c;

            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();
            result.push_back({});

            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
                result.back().push_back(products[i]);

            bsStart = start;
        }
        return result;
    }
};
