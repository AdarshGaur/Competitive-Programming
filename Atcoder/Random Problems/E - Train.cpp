// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e14;
const int mod = 1e9 +7;
const int N = 1e5 +7;
//const int mod = 998244353;

//int k[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--,y--;
    vector<pair<int, pii>> adj[n+1];
    vi dist(n+1, INF);
    vector<bool> vis(n+1, false);
    for(int i=1; i<=m; i++){
		int u, v, t, k;
		cin>>u>>v>>t>>k;
		u--;v--;
		adj[u].push_back({v, {t, k}});
		adj[v].push_back({u, {t, k}});
	}
	dist[x]=0;
	set<pii> q;
	q.insert({(int)0,x});
	while(!q.empty() and !vis[y]){
		int v = q.begin()->ss;
		int total = q.begin()->ff;
		q.erase(q.begin());
		if(vis[v])continue;
		vis[v]=true;
		for(auto e : adj[v]){
			int to = e.ff;
			int w = e.ss.ff;
			int kk = e.ss.ss;
			int wait_t = total % kk;
			if(dist[v] + wait_t + w < dist[to]){
				dist[to] = dist[v] + w + wait_t;
				q.insert({dist[to], to});
			}
		}
	}
	if(!vis[y]){
		cout<<-1<<endl;
	}else{
		cout<<dist[y]<<endl;
	}
    return 0;
}
