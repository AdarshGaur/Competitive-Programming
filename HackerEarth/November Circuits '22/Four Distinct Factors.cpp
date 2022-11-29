// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "debug.h"
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;
int const N = 1e6 +7;

vector<int> primes;
vector<bool> isPrime(N, true);
int ans[N];

void pre(){
	for(int i=2; i*i <= N; i++){
		if(!isPrime[i]) continue;
		for(int j = i*i; j < N; j += i){
			isPrime[j] = false;
		}
	}
	
	primes.push_back(2);
	for(int i=3; i <N; i+=2){
		if(isPrime[i])
			primes.push_back(i);
	}
	
	for(int i=0; i < (int)primes.size(); i++){
		for(int j = 0; j < i; j++){
			if(primes[j] * primes[i] >= N) break;
			ans[primes[j] * primes[i]] = 1;
		}
		int cube = primes[i] * primes[i] * primes[i];
		if(cube < N)
			ans[cube] = 1;
	}
	
	for(int i=1; i<N; i++)
		ans[i] += ans[i-1];
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	
	pre();

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		int l, r;
		cin >> l >> r;
		cout << ans[r] - ans[l-1] << endl;
	}
	return 0;
}
