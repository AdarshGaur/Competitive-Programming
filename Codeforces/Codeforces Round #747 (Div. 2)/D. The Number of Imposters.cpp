// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, m, ans=0;
	cin >> n >> m;
	vector<vi> g(n+m);
	int extras = n;
	for(int i=0; i<m; i++){
		string s;
		int u, v;
		cin >> u >> v >> s;
		u--, v--;
		if( s == "imposter" ){
			g[u].push_back(v);
			g[v].push_back(u);
		}else{
			g[u].push_back(extras);
			g[extras].push_back(u);
			g[extras].push_back(v);
			g[v].push_back(extras);
			extras++;
		}
	}
	vi color(extras, -1);
	for(int i=0; i<n; i++){
		if(color[i] == -1){
			queue<int> q;
			q.push(i);
			color[i] = 0;
			int c1 = 0, c2 = 0;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(u < n){
					if(color[u]) c1++;
					else c2++;
				}
				for(auto v : g[u]){
					if(color[v] == color[u]){
						cout << -1 << endl;
						return;
					}else if(color[v] == -1){
						color[v] = (color[u] + 1 )%2;
						q.push(v);
					}
				}
			}
			ans += max(c1, c2);
		}
	}
	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
