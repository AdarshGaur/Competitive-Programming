/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;


#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define pb push_back
#define ff first
#define ss second


/////// Main functions start from here ////////

#define INF 2e18
const int mod = 1e9 +7;


vvi adj;
int n, m;


void solve(){
	cin>>n>>m;
	adj.resize(n+1);
	fore(i,0,m){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int ans=0;
	vi times (n+1, 1);
	queue<int> q;
	vi d(n+1);
	vector<bool> used(n+1, false);
	q.push(1);
	used[1]=true;
	while(!q.empty()){
		int v = q.front();
		if(v==n){
			break;
		}
		q.pop();
		for(auto u: adj[v]){
			if(!used[u] || d[u]==d[v]+1){
				if(!used[u]){
					q.push(u);
					times[u] = times[v];
				}else{
					times[u] += times[v];
					times[u] %= mod;
				}
				used[u]=true;
				if(u==n && (d[n]==0 || d[n]==d[v]+1)){
					ans+=times[v];
					ans%=mod;
				}
				if(d[u]==0){
					d[u] = d[v] +1;
				}
			}
		}
	}
	cout<<ans<<endl;
}

signed main()
{
    fast_io;
	cout.precision(9);
    solve();
    return 0;
}
