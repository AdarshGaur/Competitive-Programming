// Author : Adarsh Gaur 

// #define NDEBUG
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
// int const N = 2e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m; 
	cin >> n >> m;
	vector<vi> d(n, vi(n, INF));
	for(int i=0; i<n; i++){
		d[i][i] = 0;
	}
	vector<tuple<int,int,int>> g;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({--u,--v,w});
		d[u][v] = w;
		d[v][u] = w;
	}
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 0;
	for(auto [u,v,w] : g){
		bool ok = false;
		if(d[u][v] != w ){
			ok = true;
		}
		for(int i=0; i<n; i++){
			if(i != u and i != v and d[u][i] + d[i][v] == w){
				ok = true;
				break;
			}
		}
		if(ok) ans++;
	}
	cout << ans << endl;
	return 0;
}
