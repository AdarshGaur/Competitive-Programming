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
	int n;cin>>n;
	int p[n];
	for(int i=0; i<n; i++){
		cin>>p[i];
	}
	vector<bool> vis(n+7, false);
	DSU dsu(n);
	int high = n;
	for(int i=n-1; i>=0;){
		vis[p[i]]=true;
		int cur = p[i];
		int next = cur+1;
		int j=i-1;
		while(j>=0 and (!vis[next] or !vis[high])){
			if(high<next)break;
			if(p[j]==high)high--;
			dsu.Union(cur, p[j]);
			vis[p[j]]=true;
			if(p[j]<cur){
				cur = p[j];
				next = cur+1;
			}
			while(high>0 and vis[high])high--;
			j--;
		}
		i = j;
	}
	cout<<dsu.CntofComponent()<<endl;
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
