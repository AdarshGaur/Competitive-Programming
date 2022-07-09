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
	for(int i=1; i<n; i++){
		int p; cin >> p;
		p--;
		g[p].push_back(i);
	}
	int L[n], R[n];
	for(int i=0; i<n; i++){
		cin >> L[i] >> R[i];
	}
	int ans = 0;
	function<int(int)> dfs = [&](int cur){
		int a = 0;
		for(auto v: g[cur]){
			a += dfs(v);
		}
		if(a >= L[cur] and a <= R[cur]) return a;
		else if( a > R[cur] ) return R[cur];
		ans++;
		return R[cur];
	};
	dfs(0);
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
