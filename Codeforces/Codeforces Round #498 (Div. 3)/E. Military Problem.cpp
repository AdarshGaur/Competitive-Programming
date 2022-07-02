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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n+1);
	for(int i=2; i<=n; i++){
		int p; cin >> p;
		g[p].push_back(i);
	}
	vector<int> subtree(n+1, 0), ans;
	map<int,int> mp;
	
	auto dfs = [&](auto self, int cur, int par=-1) -> int{
		int sub{};
		ans.push_back(cur);
		mp[cur] = (int)ans.size() -1;
		for(auto &v: g[cur]){
			sub += self(self, v, cur);
		}
		subtree[cur] = sub+1;
		return subtree[cur];
	};
	
	dfs(dfs, 1);
		
	for(int i=0; i<q; i++){
		int u, k;
		cin >> u >> k;
		if(subtree[u] < k){
			cout << -1 << endl;
			continue;
		}
		int x = mp[u];
		cout << ans[x+k-1] << endl;
	}
	
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
