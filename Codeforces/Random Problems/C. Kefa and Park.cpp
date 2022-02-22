// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const N = 1e5 +7;

int ans=0, n, m;
int a[N];
vector<vector<int>> e;

void dfs(int cur, int par, int consec){
	if(a[cur]==1)consec++;
	else consec=0;
	if(consec>m)return;
	if(e[cur].size()==1 and par!=-1)ans++;
	for(auto v:e[cur]){
		if(v==par)continue;
		dfs(v, cur, consec);
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	e = vector<vector<int>>(n, vector<int>());
	for(int i=0; i<n-1; i++){
		int u, v; cin>>u>>v;
		u--, v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(0, -1, 0);
	cout<<ans<<endl;
}