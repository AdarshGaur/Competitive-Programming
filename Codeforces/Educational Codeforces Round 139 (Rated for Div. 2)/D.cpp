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
vector<int> primeFact(N);

void sieve(){
	// 0, 1 are non-primes
	iota(primeFact.begin(), primeFact.end(), 0);
	for(int i = 2; i*i <= N; i++){
		if(primeFact[i] == i){
			for(int j = i*i; j <= N; j+=i ){
				if(primeFact[j] == j)
					primeFact[j] = i;
			}
		}
	}
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
			while(d > 1){
				int p = primeFact[d];
				ans = min(ans, (p - (x%p)) % p );
				d /= p;
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
