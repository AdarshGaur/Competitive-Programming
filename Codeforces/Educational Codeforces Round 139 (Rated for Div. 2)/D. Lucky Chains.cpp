// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "debug.h"
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

// #define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

// int const INF = 2e18;
int const mod = 1e9 +7;
const int N = 1e7 +7;

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

void solve(){
	int x, y, ans = mod;
	cin >> x >> y;
	if(x %2 == 0 and y%2 == 0){
		ans = 0;
	}else if(x+1 == y){
		ans = -1;
	}else if( x%2== 1 and y%2 == 1){
		ans = 0;
		if(__gcd(x,y) == 1) ans = 1;
	}else{
		if(__gcd(x,y) != 1){
			ans = 0;
		}else{
			int d = y - x;
			auto p = FindFactors(d);
			for(auto i : p){
				ans = min(ans, i - (x%i));
			}
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	
	sieve();

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
