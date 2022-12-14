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
	int n, h, m;
	cin >> n >> h >> m;
	
	int cur = h*60 +m, ans = INF;
	for(int i=0; i<n; i++){
		cin >> h >> m;
		int dif = h*60 +m - cur;
		if(dif < 0) dif += 24*60;
		ans = min(ans, dif);
	}
	
	cout << ans/60 << " " << ans%60 << endl;
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
