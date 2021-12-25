////////////////////////// Author : Adarsh Gaur ////////////////////////////

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




/////////////////////// Main functions start from here ///////////////////////

const int MAXN = 1e6+2;

vvi adj(MAXN);
vector <int> used(MAXN);
vi d(MAXN);

bool bfs_with_height(int node, int power){
	if(used[node]!=-1){
		return false;
	}
	queue<int> q;
	q.push(node);
	used[node]=node;
	d[node]=0;
	while(!q.empty()){
		int v = q.front();
		if(d[v]==power){
			break;
		}
		q.pop();
		for(int u: adj[v]){
			if(used[u]!=node && used[u]!=-1){
				return false;
			}else if(used[u]==node){
				continue;
			}else{
				used[u]=node;
				q.push(u);
				d[u]=d[v]+1;
			}
		}
	}
	return true;
}


void solve(){
	int n, r, m;
	cin>>n>>r>>m;
	adj.clear();
	adj.resize(n+1);
	used.clear();
	used.resize(n+1);
	d.clear();
	d.resize(n+1);
    for(auto &i: used){
        i=-1;
    }

	for(int i=0;i<r; i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bool ans=true;
	int power[m], nodes[m];
	for(int i=0;i<m;++i){
		cin>>nodes[i]>>power[i];
	}
	if(m>n){
		ans=false;
	}



	for(int i=0;i<m && ans;++i){
		ans=bfs_with_height(nodes[i],power[i]);
	}
	for(int i=1;i<=n;i++){
		if(used[i]==-1){
			ans=false;
			break;
		}
	}
	if(!ans){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
}

signed main()
{
    fast_cin();
    int it;cin >> it;
    for(int i=1;i<=it; ++i){
    solve();
    }
    return 0;
}