/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; ++i)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define pb push_back
#define ff first
#define ss second


#ifndef ONLINE_JUDGE
#define aster(x) cerr<<#x<<" = "<<x<<endl;  // aster is my friend
#else
#define aster(x)
#endif


#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

const int N = 1e5 +7;
vector<vi> adj;
int dp[2][N];
vector<pii> lr;


void dfs(int cur, int par){
	////////////////////////
	dp[0][cur] = dp[1][cur]= 0;
	for(auto i:adj[cur]){
		if(i!=par){
			dfs(i, cur);
			dp[0][cur] += max(abs(lr[cur].ff - lr[i].ff)+dp[0][i], abs(lr[cur].ff - lr[i].ss) +dp[1][i]);
			dp[1][cur] += max(abs(lr[cur].ss - lr[i].ff) +dp[0][i], abs(lr[cur].ss - lr[i].ss) +dp[1][i]);
		}
	}
}


void solve(){
	int n;cin>>n;
	lr.clear();
	lr.pb({0,0});
	adj.clear();
	adj.resize(n+1, vi());
	fore(i,0,n){
		int x, y;
		cin>>x>>y;
		lr.pb({x,y});
	}
	for(int i=1; i<n; i++){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,-1);
	cout<<max(dp[0][1], dp[1][1])<<endl;
}

int32_t main()
{
    fast_io;
    cout.precision(20);
    //makepower();
    int times;cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
