# Sieve of Eratosthenes and Its Optimization

## Overview

The **Sieve of Eratosthenes** is an ancient algorithm used to find all prime numbers up to a given limit `n`. It works by iteratively marking the multiples of each prime number starting from 2. The remaining unmarked numbers are primes.

### Steps of the Basic Algorithm:
1. Create a boolean array `prime[0..n]` and initialize all entries as `true`. 
2. Set `prime[0]` and `prime[1]` to `false` since 0 and 1 are not prime numbers.
3. For each number `p` from 2 to √n:
   - If `prime[p]` is `true`, then mark all multiples of `p` (starting from `p^2`) as `false`.
4. The numbers which remain `true` are primes.

## Optimized Approach

An optimization of the Sieve of Eratosthenes involves the following:
1. **Upper Limit Optimization**: Instead of marking multiples up to `n`, the optimization marks multiples up to `sqrt(n)`. This reduces the time complexity and number of iterations.
2. **Memory Optimization**: We can reduce the space complexity by using an array of size `n/2` by only storing odd numbers, as even numbers (other than 2) are not prime.

### C++ Code Example

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize all entries as true
    vector<bool> prime(n + 1, true);

    // 0 and 1 are not prime numbers
    prime[0] = prime[1] = false;

    // Only go up to sqrt(n) because we only need to mark multiples up to n
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            // Mark all multiples of p as false
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print the primes
    cout << "Prime numbers up to " << n << ": ";
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 30; // Example input
    sieveOfEratosthenes(n);
    return 0;
}
