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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
int const N = 1e5 + 7;

vector<vector<pii>> g;
int a[N];

void dfs(int cur, int par, int val){
	for(auto [v,i] : g[cur]){
		if(v==par)continue;
		a[i] = val;
		dfs(v, cur, val^1);
	}
}

void solve(){
	int n;cin>>n;
	g = vector<vector<pii>>(n);
	for(int i=0; i<n-1; i++){
		int u, v;cin>>u>>v;
		u--, v--;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	int start=-1;
	for(int i=0; i<n; i++){
		if( g[i].size() >2 ){
			cout<<-1<<endl;
			return;
		}
		if(g[i].size() == 1)
			start=i;
	}
	dfs(start, -1, 0);
	for(int i=0; i<n-1; i++){
		cout<<a[i]+2<<" ";
	}
	cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    cin.exceptions(cin.failbit);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
