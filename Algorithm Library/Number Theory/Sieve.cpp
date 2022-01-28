// Simple Sieve
// Time Complexity of this method is strictly less than O(NloglogN)
//					- and it takes O(N) memory.

const int N = 1e6+7;

vector<int> primes;
vector<bool> isPrime(N, true);	//isPrime[i] indicates i is prime.

void sieve(){
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
