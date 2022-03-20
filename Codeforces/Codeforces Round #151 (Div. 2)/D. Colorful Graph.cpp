// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
int const N = 1e5 + 7;

void solve(){
	int n, m, color=INF;
	cin >> n >> m;
	int c[n], deg[N];
	memset(deg, 0, sizeof(deg));
	for(int i=0; i<n; i++){
		cin >> c[i];
		color = min(c[i], color);
	}
	map<pii, bool> mp;
	for(int i=0; i<m; i++){
		int u, v; cin >> u >> v;
		u--, v--;
		if(c[u] == c[v])continue;
		u = c[u], v = c[v];
		if(mp.count({u,v}) or mp.count({v,u})) continue;
		mp[{u,v}] = true;
		deg[u]++;
		deg[v]++;
	}
	int cardinality = 0;
	for(int i=0; i<N; i++){
		if(deg[i] > cardinality){
			color = i;
			cardinality = deg[i];
		}
	}
	cout << color << endl;
}

int32_t main()
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
