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
// int const N = 1e5 + 7;
int n, m;
vector<vi> adj;
vector<bool> vis;


void solve(){
	cin>>n>>m;
	adj = vector<vi>(n);
	vis = vector<bool>(n, false);
	for(int i=0; i<m; i++){
		int u, v;cin>>u>>v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	int ans=0;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			int t=1;
			deque<int> q;
			q.push_back(i);
			while(!q.empty()){
				int u = q.front();
				q.pop_front();
				if(adj[u].size() != ii(2)){
					t=0;
				}
				for(auto v: adj[u]){
					if(!vis[v]){
						vis[v]=true;
						q.push_back(v);
					}
				}
			}
			ans += t;
		}
	}
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
