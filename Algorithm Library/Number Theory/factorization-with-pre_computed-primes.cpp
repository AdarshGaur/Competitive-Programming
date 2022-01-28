// Factorization with pre-computed Primes
//	to find the factor as prime power in the form of 2^a, 3^b, 5^c ...

// Time complexity is around O(logn);

const int N = 1e6 +7;

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

// n must be more than 1
vector<pair<int, int> > FindFactors(int n){
	vector<pair<int,int> > factors;
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
			factors.push_back({i,p});
		}
	}
	if(n > 1){
		factors.push_back({n,1});
	}
	return factors;
}