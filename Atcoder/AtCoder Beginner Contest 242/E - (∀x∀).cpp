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
int const mod = 998244353;

int modpow(int a,int b){
	int r = 1;
	while(b){
		if(b&1){
			r = (r * a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return r;
}


void solve(){
	int n;
	string s;
	cin >> n >> s;
	
	int ans = 0, mid = (n+1)/2 -1;
	for(int i=0; i<=mid; i++){
		int d = s[i] - 'A';
		ans += (d * modpow(26, mid - i));
		ans %= mod;
	}
	
	string rev = s.substr(0, n/2);
	reverse(rev.begin(), rev.end());
	
	if(rev <= s.substr(mid+1)){
		ans++;
	}
	
	cout << ans % mod << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
