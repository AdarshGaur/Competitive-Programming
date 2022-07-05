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

bool query(int l, int r){
	// 1 - based indexing used here
	cout << "? " << l << " " << r << "\n" << flush;
	int fixed = 0;
	for(int i=l; i<=r; i++){
		int x; cin >> x;
		if(x == -1) exit(0);
		fixed += (x >= l and x <= r ? 1 : 0);
	}
	return fixed &= 1;
}

void solve(){
	int n;
	cin >> n;
	int lo = 1, hi = n, ans = n;
	while(lo < hi){
		int m = (lo + hi)/2;
		if(query(lo, m)){
			hi = m;
			ans = m;
		}else{
			lo = m+1;
		}
	}
	cout << "! " << ans << "\n" << flush;
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
