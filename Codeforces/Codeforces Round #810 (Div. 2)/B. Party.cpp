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
	vector<vector<int>> g(n);
	vector<int> deg(n, 0), a(n);
	for(int &i: a)
		cin >> i;
	
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	
	if(m %2 == 0){
		cout << 0 << endl;
		return ;
	}
	
	int ans = INF;	
	for(int i=0; i<n; i++){
		if(deg[i]&1){
			ans = min(ans, a[i]);
		}
	}
	
	vector<bool> vis(n, false);
	
	auto dfs = [&](auto self, int cur) -> void{
		vis[cur] = true;
		for(auto v: g[cur]){
			if(deg[cur]%2 == 0 and deg[v]%2 == 0){
				ans = min(ans, a[cur]+a[v]);
			}
			if(vis[v]) continue;
			self(self, v);
		}
	};
	
	for(int i=0; i<n; i++){
		if(!vis[i])
			dfs(dfs, i);
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
