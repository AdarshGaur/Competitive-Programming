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

const int N = 1e5 +7;
int X[N];
vector<vector<int>> G, ans;


void dfs(int cur, int par){
	priority_queue<int, vector<int>, greater<>> pq;
	pq.push(X[cur]);
	for(auto &v: G[cur]){
		if(v == par) continue;
		dfs(v, cur);
		for(auto &val: ans[v]){
			pq.push(val);
			if((int)pq.size() > 20){
				pq.pop();
			}
		}
	}
	
	while(!pq.empty()){
		ans[cur].push_back(pq.top());
		pq.pop();
	}
	reverse(ans[cur].begin(), ans[cur].end());
	return;
}


void solve(){
	int n, Q;
	cin >> n >> Q;

	for(int i=0; i<n; i++){
		cin >> X[i];
	}
	
	G.resize(n);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	ans.resize(n);
	dfs(0, -1);
	
	while(Q--){
		int v, k;
		cin >> v >> k;
		cout << ans[v-1][k-1] << endl;
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
