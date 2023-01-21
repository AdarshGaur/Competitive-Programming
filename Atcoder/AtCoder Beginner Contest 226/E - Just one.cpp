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
int const mod = 998244353;


void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> G(n);
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	vector<bool> vis(n, false);
	
	auto dfs = [&](auto self, int cur, int par, int &nodes, int &edges) -> void {
		vis[cur] = true;
		nodes += 1;
		edges += (int)G[cur].size();
		for(auto &v: G[cur]){
			if(v != par and !vis[v])
				self(self, v, cur, nodes, edges);
		}
		return ;
	};
	
	int ans = 1;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			int nodes = 0, edges = 0;
			dfs(dfs, i, -1, nodes, edges);
			if(nodes * 2 == edges){
				ans <<= 1;
				ans %= mod;	
			}else{
				ans = 0;
			}
		}
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
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
