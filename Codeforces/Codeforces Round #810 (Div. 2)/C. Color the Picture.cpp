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
// int const N = 2e5 + 7;


void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[k];
	for(int &i: a)
		cin >> i;
	sort(a, a+k);
	int rn = n, rm = m;
	for(int i=0; i<k; i++){
		if(a[i] >= m*2){
			int t = a[i]/m;
			if(t >= rn)
				t = rn;
			else if(t < rn)
				t = min(t, rn -2);
			debug(a[i], t, rn);
			if(t != 1)
				rn -= t;
		}
		if(a[i] >= n*2){
			int t = a[i]/n;
			if(t >= rm)
				t = rm;
			else if(t < rm)
				t = min(t, rm -2);
			debug(a[i], rm, t);
			if(t != 1)
				rm -= t;
		}
		if(rm == 0 or rn == 0) break;
	}
	cout << (rm == 0 or rn == 0 ? "YES" : "NO" ) << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
