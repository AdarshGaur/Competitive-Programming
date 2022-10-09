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
	int n;
	cin >> n;
	
	int mn = INF, mx = -INF;
	
	int x[n], t[n];
	for(int i=0; i<n; i++){
		cin >> x[i];
	}
	for(int i=0; i<n; i++){
		cin >> t[i];
		mn = min(mn, x[i] - t[i]);
		mx = max(mx, x[i] + t[i]);
	}
	
	cout << mn + (mx-mn)/2.0 << endl;
	
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
