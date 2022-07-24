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
	int n, m;
	cin >> n >> m;
	vector<int> deg(n, 0), a(n);
	for(int &i: a)
		cin >> i;
	
	int ans = m%2 == 0 ? 0 : INF;
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		deg[u]++, deg[v]++;
		ans = min(ans, a[u] + a[v]);
	}
	
	for(int i=0; i<n; i++){
		if(deg[i]&1){
			ans = min(ans, a[i]);
		}
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
