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
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	map<int,int> mp;
	bool pos = true;
	int f[n+1]{};
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		if( a == b) pos = false;
		f[a]++, f[b]++;
		if(mp.count(a)){
			int v = mp[a];
			g[v].push_back(i);
			g[i].push_back(v);
		}else{
			mp[a] = i;
		}
		if(mp.count(b)){
			int v = mp[b];
			g[v].push_back(i);
			g[i].push_back(v);
		}else{
			mp[b] = i;
		}
	}
	for(int i=1; i<=n; i++){
		if(f[i] != 2)
			pos =false;
	}
	if(!pos){
		cout << "NO" << endl;
		return;
	}
	vector<bool> vis(n, false);
	vector<int> color(n, -1);
	auto dfs = [&](auto self, int cur, int c)->void{
		color[cur] = c;
		for(auto &v: g[cur]){
			if(!vis[v]){
				color[v] = color[cur]^1;
				vis[v] = true;
				self(self, v, color[v]);
			}
			if(color[cur] == color[v])
				pos = false;
		}
	};
	for(int i=0; i<n; i++){
		if(!vis[i]){
			vis[i] = true;
			dfs(dfs, i, 0);
		}
	}
	cout << (pos ? "YES" : "NO") << endl;
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
