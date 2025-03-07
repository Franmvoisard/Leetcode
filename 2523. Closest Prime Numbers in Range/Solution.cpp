class Solution {

private:
    vector<int> getPrimeNumbers(int min, int limit){
        vector<bool> isPrime(limit+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        vector<int> primes;
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int i = min; i <= limit; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        return primes;
    };

    public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> result = {-1, -1};
        vector<int> primes = getPrimeNumbers(left, right);
        int minDifference = INT_MAX;

        for(int i = 1; i < primes.size(); i++){
            int substractionResult = primes[i] - primes[i-1];
            if(primes[i] - primes[i-1] < minDifference){
                minDifference = substractionResult;
                result = {primes[i-1], primes[i]};
            }
        }
        return result;
    }
};
