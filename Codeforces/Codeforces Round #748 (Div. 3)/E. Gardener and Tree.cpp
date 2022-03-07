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
	int n, k;
	cin >> n >> k;
	vector<int> g[n];
	int deg[n];
	memset(deg, 0, sizeof(deg));
	for(int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		u-- , v-- ;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	queue<int> q;
	vector<int> kt(n, 0);
	for(int i=0; i<n; i++){
		if(deg[i] <= 1){
			kt[i] = 1;
			q.push(i);
		}
	}
	int left = n;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		left--;
		if(kt[cur] == k)continue;
		for(auto v : g[cur]){
			if(kt[v]==0){
				deg[v]--;
				if(deg[v] <= 1){
					q.push(v);
					kt[v] = kt[cur] + 1;
				}
			}
		}
	}
	cout << left << endl;
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
