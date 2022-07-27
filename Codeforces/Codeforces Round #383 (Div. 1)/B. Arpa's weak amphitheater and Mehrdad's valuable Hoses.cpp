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
	int n, m, W;
	cin >> n >> m >> W;
	
	vector<int> w(n+1, 0), b(n+1, 0);
	for(int i=1; i<=n; i++)
		cin >> w[i];
	for(int i=1; i<=n; i++)
		cin >> b[i];
	
	vector<bool> vis(n+1, false);
	vector<vector<int>> g(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> t;
	function<pii(int)> dfs = [&](int cur){
		vis[cur] = true;
		t.push_back(cur);
		int tw = w[cur], tb = b[cur];
		for(auto &v: g[cur]){
			if(!vis[v]){
				auto [ww, bb] = dfs(v);
				tw += ww, tb += bb;
			}
		}
		return make_pair(tw, tb);
	};
	
	vector<vector<pii>> store;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			auto [totalW, totalB] = dfs(i);
			store.push_back({});
			for(auto j: t){
				store.back().push_back({w[j], b[j]});
			}
			store.back().push_back({totalW, totalB});
			t.clear();
		}
	}
	
	int ans{};
	vector<int> dp(W+1, 0);
	for(int i=0; i<(int)store.size(); i++){
		for(int j=W; j>0; j--){
			for(auto &[totalW, totalB]: store[i]){
				if(j < totalW) continue;
				dp[j] = max(dp[j], dp[j-totalW] + totalB);
			}
			ans = max(ans, dp[j]);
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
