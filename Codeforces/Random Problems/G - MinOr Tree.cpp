// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> item;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

struct DSU{
	vector<int> par, weight;
	int components, nodes;

	DSU(int n){
		nodes = n;
		components = n;
		par.resize(n+1);
		weight.resize(n+1, 1);
		iota(par.begin(), par.end(), 0);
	}

	int Find(int v){ // find set with path compression
		if(v==par[v])
			return v;
		return par[v] = Find(par[v]);
	}

	bool Union(int a, int b){
		a = Find(a), b = Find(b);
		if(a == b) return false;
		if(weight[a] > weight[b]){
			swap(a,b);
		}
		par[a] = b;
		weight[b] += weight[a];
		components -= 1;
		return true;
	}

	int CntofComponent(){ // return the total number of components
		return components;
	}

	int NodeinComponent(int x){ // return the number of nodes in component x;
		return weight[Find(x)];
	}
};

void solve(){
	int n, m;cin>>n>>m;
	vector<item> e(m);
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		u--, v--;
		e[i] = {u, v, w};
	}
	int ans=0, high=0;
	for(int i=0; i<32; i++)high|=(1ll<<i);
	for(int i=31; i>=0; i--){
		DSU dsu(n);
		for(auto [u,v,w]:e){
			if((w&(1ll<<i))==0){
				dsu.Union(u,v);
			}
		}
		if(dsu.CntofComponent()!=1){
			ans |= (1ll<<i);
		}else{
			for(int j=0; j<m; j++){
				auto [u, v, w] = e[j];
				if(w&(1ll<<i)){
					e[j] = {u,v,high};
				}
			}
		}
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
