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
	int ans = 0, mn = INF, mx = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if(i > 0){
			ans += abs(a[i] - a[i-1]);
		}
	}
	
	if(mn > 1){
		ans += min({a[0] -1, 2 * (mn-1), a[n-1] -1});
	}
	
	if(mx < x){
		ans += min({x-a[0], 2 * (x - mx), x - a[n-1]});
	}
	
	cout << ans << endl;
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
