// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const N = 1e5 + 7;
int xr, ans;
int sub[N], a[N];
vector<vi> g;


int dfs(int u, int par){
	sub[u] = a[u];
	for(auto v : g[u]){
		if(v == par)continue;
		sub[u] ^= dfs(v, u);
	}
	if(sub[u] == xr){
		ans++;
		sub[u] = 0;
	}
	return sub[u];
}

string solve(){
	xr = 0, ans = 0;
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	g = vector<vi>(n);
	for(int i=1; i<n; i++){
		int u, v; cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	xr=0;
	for(int i=0; i<n; i++) xr ^= a[i];
	if(xr == 0) return "YES";
	if(k == 2) return "NO";
	sub[0] = dfs(0, -1);
	if(ans >= 3) return "YES";
	return "NO";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		cout << solve() << endl;
	}
	return 0;
}
