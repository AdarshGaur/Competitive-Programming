/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
//#include <array>
//#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<pii> vpii;


#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forn(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define dbg(x) cout<<#x<<" = "<<x<<endl

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define endl "\n"

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////// Main functions start from here ////////

const int mod = 1e9 +7;
//const int maxn = 1e5 +3;
vvi adj;
vector<bool> visited;
int members=0;

void dfs(int node, int par){
	if(visited[node]){
		return;
	}
	members++;
	visited[node]=true;
	for(auto i:adj[node]){
		if(i==par){
			continue;
		}
		dfs(i,node);
	}
	return ;
}

void solve(){
	int n,m;
	cin>>n>>m;
	adj.clear();
	adj.resize(n+1);
	visited.clear();
	visited.resize(n+1);
	visited.assign(n+1,false);
	forn(i,0,m){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int i=1, count=0, ans=1;
	while(i<=n){
		if(!visited[i]){
			dfs(i,-1);
			ans = (ans * members)%mod;
			count++;
			members=0;
		}
		i++;
	}
	cout<<count<<" "<<ans%mod<<endl;
}

signed main()
{
    fast_cin();
    int it;cin >> it;
    for(int i=1;i<=it; ++i){
    //cout<<"Case #"<< i << ": ";
    solve();
    }
    return 0;
}
