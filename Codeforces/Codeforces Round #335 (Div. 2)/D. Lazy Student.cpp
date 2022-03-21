// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

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
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edge;
	for(int i=0; i<m; i++){
		int w, p;
		cin >> w >> p;
		if(p) p = 0;
		else p = 1;
		edge.push_back({w, p, i});
	}
	sort(edge.begin(), edge.end());
	vector<tuple<int, int, int>> g;
	int from=2, to = 3, next=2;
	for(int i=0; i<m; i++){
		auto [w, p, k] = edge[i];
		if(p == 0){
			g.push_back({k, 1, next++});
		}else{
			if(to >= next){
				cout << -1 << endl;
				return;
			}
			g.push_back({k, from, to});
			from++;
			if(from >= to){
				to++;
				from=2;
			}
		}
	}
	sort(g.begin(), g.end());
	for(auto [k, u, v] : g){
		cout << u << " " << v << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
