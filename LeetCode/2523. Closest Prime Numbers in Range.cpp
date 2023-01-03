// Author: @AdarshGaur

class Solution {
public:
    vector<int> primes;
    vector<bool> isPrime;	//isPrime[i] indicates i is prime.

    void sieve(int N){
        isPrime.resize(N, true);
        // 0, 1 are non-primes
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i*i <= N; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= N; j+=i ){
                    isPrime[j] = false;
                }
            }
        }

        // storing the prime numbers till N;
        primes.push_back(2);
        for(int i=3; i<=N; i+=2){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
    }
    
    vector<int> closestPrimes(int left, int right) {
        sieve(1e6 +7);
        int start = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        int l = -1e9, r = 1e9;
        for(int i = start+1; i< primes.size(); i++){
            if(primes[i] > right) break;
            long d = primes[i] - primes[i-1];
            if(primes[i] - primes[i-1] < 1l*r - l)
                l = primes[i-1], r = primes[i];
        }
        if(l == -1e9 and r == 1e9)
            return {-1,-1};
        return {l, r};
    }
};
