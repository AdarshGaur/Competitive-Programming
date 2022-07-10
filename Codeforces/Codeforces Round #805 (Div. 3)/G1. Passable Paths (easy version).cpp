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



signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	// g1 - easy
	
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q;
	cin >> q;
	while(q--){
		int k, x; cin >> k;
		set<int> s;
		for(int i=0; i<k; i++){
			cin >> x;
			x--;
			s.insert(x);
		}
		int exclude=-1, cnt{};
		function<bool(int,int)> dfs = [&](int cur, int par=-1){
			bool pos = false;
			for(auto v: g[cur]){
				if(v == par) continue;
				if(dfs(v, cur)){
					exclude = v;
					pos = true;
					break;
				}
			}
			if(s.count(cur)){
				cnt++;
				pos = true;
			}
			return pos;
		};
		dfs(x, -1);
		int par = exclude;
		if(par != -1){
			dfs(x, par);
			cnt--;
		}
		if(cnt != (int)s.size()){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	return 0;
}
