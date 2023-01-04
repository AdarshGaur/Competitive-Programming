// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "debug.h"
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	int n, m;
	cin >> n >> m;
	
	queue<pii> q;
	
	vector<vector<int>> mat(m);
	for(int i=0; i<m; i++){
		int k; cin >> k;
		for(int j=0; j<k; j++){
			int x;cin >> x;
			mat[i].push_back(x);
		}
		q.push({mat[i].back(), i});
	}
	
	map<int, bool> present;
	map<int, int> c2i;
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		if(present.count(p.first)){
			// erase p.first from present
			for(int i: {p.second, c2i[p.first]}){
				mat[i].pop_back();
				if(!mat[i].empty()){
					q.push({mat[i].back(), i});
				}
			}
		}else{
			present[p.first] = true;
			c2i[p.first] = p.second;
		}
	}
	
	bool ok = true;
	for(int i=0; i<m; i++){
		ok = ok & mat[i].empty();
	}
	cout << (ok ? "Yes" : "No" ) << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
