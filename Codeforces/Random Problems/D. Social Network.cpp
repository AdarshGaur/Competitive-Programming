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

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, d;cin>>n>>d;
	DSU dsu(n);
	int extra=1;
	for(int i=0; i<d; i++){
		int x, y;cin>>x>>y;
		if(!dsu.Union(x, y)){
			extra++;
		}
		vi ss(n+1, -1);
		for(int j=1; j<=n; j++){
			ss[dsu.Find(j)] = dsu.NodeinComponent(j);
		}
		sort(ss.rbegin(), ss.rend());
		int all = 0;
		for(int j=0; j<extra; j++){
			all += ss[j];
		}
		cout<<all-1<<endl;
	}
	return 0;
}
