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
typedef tuple<int,int,int> edge;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	int n;
	cin >> n;
	
	auto g = vector<vector<edge>>(n+1);
	for(int i=2; i<=n; i++){
		int p, a, b;
		cin >> p >> a >> b;
		g[p].push_back({i, a, b});
	}
	
	vector<int> ans(n+1), B;
	auto dfs = [&](auto self, int cur, int a) -> void{
		
		ans[cur] = upper_bound(B.begin(), B.end(), a) - B.begin() -1;
		
		for(auto [v, aa, bb]: g[cur]){
			B.push_back(bb+ B.back());
			self(self, v, a+aa);
			B.pop_back();
		}
		
	};
	
	B.push_back(0);
	dfs(dfs, 1, 0);
	
	for(int i=2; i<=n; i++){
		cout << ans[i] << " \n"[i == n];
	}
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
