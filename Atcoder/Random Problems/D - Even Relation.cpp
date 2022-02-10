// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
int const N = 1e5 + 7;

vector<vector<pii>> g;
int color[N];

void dfs(int cur, int par, int c){
	color[cur] = c;
	for(auto [v,w] : g[cur]){
		if(v==par)continue;
		int cc=c;
		if(w%2!=0){
			cc = 1-c;
		}
		dfs(v, cur, cc);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n;cin>>n;
	g = vector<vector<pii>>(n);
	memset(color, -1, sizeof(color));
	for(int i=1; i<n; i++){
		int u, v, w;cin>>u>>v>>w;
		u--, v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1, -1, 0);
	for(int i=0; i<n; i++){
		cout<<color[i]<<endl;
	}
	return 0;
}
