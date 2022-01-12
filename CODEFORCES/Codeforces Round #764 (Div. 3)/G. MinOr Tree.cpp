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

int const INF = 2e14;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

int n, m;
vector<vector<pii>> g;
vector<bool> vis;

void dfs(int u, int &cur){
	if(vis[u])return;
	vis[u]=true;
	for(auto e: g[u]){
		int v = e.first, w = e.second;
		if(!vis[v] and (cur|w)==cur)
			dfs(v,cur);
	}
}

void solve(){
	cin>>n>>m;
	g.assign(n, vector<pii>());
	for(int i=0; i<m; i++){
		int u, v , w;
		cin>>u>>v>>w;
		g[--u].push_back({--v,w});
		g[v].push_back({u,w});
	}
	int res=0, bit=0;
	while(res < INF){
		res |= (1ll<<bit);
		bit++;
	}
	for(int i=bit-1; i>=0; i--){
		vis.assign(n, false);
		res -= (1ll<<i);
		dfs(0, res);
		for(auto j: vis){
			if(!j){
				res += (ii(1)<<i);
				break;
			}
		}
	}
	cout<<res<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
