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
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, k;
	cin >> n >> k;
	int u[n];
	for(int &i: u)
		cin >> i;
	map<int, vector<int>> mp;
	for(int i=0; i<n; i++){
		if(mp.count(u[i])){
			if(mp[u[i]].size() > 1){
				mp[u[i]].pop_back();
			}
			mp[u[i]].push_back(i);
		}else{
			mp[u[i]] = {i};
		}
	}
	while(k--){
		int a, b;
		cin >> a >> b;
		string pos = "NO";
		for(auto &v: mp[a]){
			for(auto &x: mp[b]){
				if(v < x)
					pos = "YES";
			}
		}
		cout << pos << endl;
	}
}

signed main()
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
