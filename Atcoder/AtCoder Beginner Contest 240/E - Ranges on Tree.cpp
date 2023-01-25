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
	
	vector<vector<int>> g(n);
	for(int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	pii ans[n];
	
	function<int(int,int,int)> dfs = [&](int cur, int par, int l){
		int r = l -1;
		for(auto &v: g[cur]){
			if(v == par) continue;
			r = dfs(v, cur, r+1);
		}
		if(r == l-1) r++;
		ans[cur] = {l, r};
		return r;
	};
	
	dfs(0, -1, 1);
	
	for(auto &[l, r]: ans){
		cout << l << " " << r << endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
