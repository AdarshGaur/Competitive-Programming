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
// int const N = 2e5 + 7;


struct DSU{
	vector<int> par, weight;
	int components, nodes;

	DSU(int n){
		nodes = n;
		components = n;
		par.resize(n+1);
		weight.resize(n+1, 1);
		iota(par.begin(), par.end(), 0); // ** 1-indexing **
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int n, m, q;
    cin>>n>>m>>q;
    typedef tuple<int,int,int, int> item;
    vector<item> edges;
    for(int i=0; i<m; i++){
		int u,v,w;cin>>u>>v>>w;
		edges.push_back(make_tuple(w,u,v,-1));
	}
	for(int i=0; i<q; i++){
		int u,v,w;cin>>u>>v>>w;
		edges.push_back(make_tuple(w,u,v,i));
	}
	
	DSU dsu(n);
	sort(edges.begin(), edges.end());
	vector<string> ans(q, "No");
	for(auto [w,u,v,indx] : edges){
		if(dsu.Find(u) != dsu.Find(v)){
			if(indx==-1){
				dsu.Union(u,v);
			}else{
				ans[indx] = "Yes";
			}
		}
	}
	for(auto i: ans){
		cout<<i<<endl;
	}
    return 0;
}
