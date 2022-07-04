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
// int const mod = 998244353;
const int MAXN = 1e5 + 7;

//pre-compute factorial values
int f[MAXN];
int invf[MAXN];

//make factorials upto required before any ohter computation
void factorial(){
	//factorials % mod
	f[0] = 1;
	invf[0] = invf[1] = 1;
	for(int i = 1; i < MAXN; i++){
		f[i] = (f[i-1] *i) %mod;
	}
	for(int i=2; i<MAXN; ++i){
		invf[i] = (mod - mod/i) * invf[mod % i] % mod;
	}
	for(int i=1;i<MAXN; ++i){
		invf[i] = (invf[i-1] * invf[i])%mod;
	}
}

int nCr(int n, int r){
	//base Case
	if(r==0) return 1;
	if(n<r) return 0;
	
	int res = (f[n] * invf[r])%mod;
	return  (res * invf[n-r])%mod ;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0; i<n; i++){
		cin >> a[i];
		mp[a[i]] = i;
	}
	int mn = mp[0], mx = mp[0], ans = 1;
	for(int i=1; i<n; i++){
		int j = mp[i];
		if(j >= mn and j <= mx) continue;
		int gap = j - mx -1;
		if(j < mn)
			gap = mn - j -1;
		mn = min(mn, j);
		mx = max(mx, j);
		int dif = mx - mn;
		int extra = dif - i;
		int x = nCr(extra, gap) * f[gap];
		x %= mod;
		ans = (ans * x) %mod;
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	factorial();
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
