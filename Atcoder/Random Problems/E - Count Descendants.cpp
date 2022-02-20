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
int const N = 2e5 + 7;

int n, timer=0;
vector<vi> g, levels;
int ins[N], outs[N], level[N];

void dfs(int cur){
	levels[level[cur]].push_back(timer);
	ins[cur] = timer++;
	for(auto v:g[cur]){
		level[v] = level[cur]+1;
		dfs(v);
	}
	outs[cur] = timer++;
}

void solve(){
	cin>>n;
	g.resize(n);
	levels.resize(n);
	timer = 0;
	for(int i=1; i<n; i++){
		int p;cin>>p;
		g[p-1].push_back(i);
	}
	dfs(0);
	int q;cin>>q;
	while(q--){
		int u, d;cin>>u>>d;
		u--;
		auto& v = levels[d];
		int cnt = lower_bound(v.begin(), v.end(), outs[u]) - lower_bound(v.begin(), v.end(), ins[u]);
		cout<<cnt<<endl;
	}
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
