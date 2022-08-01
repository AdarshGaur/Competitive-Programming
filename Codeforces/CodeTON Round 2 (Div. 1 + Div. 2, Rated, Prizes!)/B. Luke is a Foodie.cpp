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


void solve(){
	int n, x;
	cin >> n >> x;
	int a[n];
	for(int &i: a)
		cin >> i;
	int l = a[0]-x, r = a[0]+x, ans{};
	for(int i=1; i<n; i++){
		int lx = a[i]-x, rx = a[i]+x;
		l = max(l, lx);
		r = min(r, rx);
		if(l <= r) continue;
		ans++;
		l = lx, r = rx;
	}
	cout << ans << endl;
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
