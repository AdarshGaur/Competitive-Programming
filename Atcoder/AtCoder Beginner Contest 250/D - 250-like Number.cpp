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
int const maxn = 1e6;


void solve(){
	int n;
	cin >> n;
	
	vector<int> primes;
	vector<bool>isprime(maxn, true);
	
	isprime[0] = isprime[1] = false;
	for(int i=2; i<maxn; i++){
		if(isprime[i]){
			primes.push_back(i);
			for(int j=i+i; j<maxn; j+=i){
				isprime[j] = false;
			}
		}
	}
	
	int ans{};
	for(int i=1; i<(int)primes.size(); i++){
		int q = primes[i] * primes[i] * primes[i];
		if(q >= n) break;
		int x = n / q;
		for(int &p : primes){
			if(p == primes[i]) break;
			if(p > x) break;
			ans++;
		}
	}
	
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
