// Author: @AdarshGaur

class Solution {
public:

    vector<int> primes;
    vector<bool> isPrime;	//isPrime[i] indicates i is prime.
    
    void sieve(const int N){
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

    // n must be more than 1
    vector<int> FindFactors(int n){
        vector<int> factors;
        for(auto i : primes){
            if(i*i > n){
                break;
            }
            int p=0;
            while(n%i == 0){
                p++;
                n/=i;
            }
            if(p!=0){
                factors.push_back(i);
            }
        }
        if(n > 1){
            factors.push_back(n);
        }
        return factors;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        sieve(1007);
        set<int> s;
        for(int &i: nums){
            for(auto &j: FindFactors(i)){
                s.insert(j);
            }
        }
        return s.size();
    }
};
