class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        if(total < k) return 0;
        int left = 1;
        int right = floor(total / k);
        int res = 0;
        int m = 0;

        while(left <= right){
            m = left + (right-left) / 2;

            long long count = 0;
            for(long long candy : candies){
                if (candy >= m){
                    count += candy / m;
                }
                if(count >= k){
                    break;
                }
            }
            if(count >= k){
                res = m;
                left = m + 1;
            }
            else{
                right = m - 1;
            }
        }   
        return res;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
};
