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

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;

vector<vi> children, levels;
vi in, out, depth;
int timer=0;

void dfs(int u){
	in[u] = timer++;
	levels[depth[u]].push_back(in[u]);
	for(auto i : children[u]){
		depth[i] = depth[u]+1;
		dfs(i);
	}
	out[u]=timer++;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout.precision(10);
	
	int n;cin>>n;
	children = levels = vector<vi>(n);
	in = out = depth = vi(n,0);
	for(int i=1; i<n; i++){
		int p; cin>>p;
		children[p-1].push_back(i);
	}
	dfs(0);
	int q;cin>>q;
	while(q--){
		int u, d;cin>>u>>d;
		u--;
		cout<<lower_bound(levels[d].begin(), levels[d].end(), out[u]) -
				lower_bound(levels[d].begin(), levels[d].end(), in[u]) <<endl;
	}
    return 0;
}
