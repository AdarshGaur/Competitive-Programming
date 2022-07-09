// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

// #ifdef cicada
// #include "debug.h"
// #else
// #define debug(...) "Yume o akiramete shinde kure."
// #endif

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n;
	cin >> n;
	cout << 2 << endl;
	bool vis[n+1]{};
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			for(int j=i; j<=n; j+=j){
				cout << j << " ";
				vis[j] = true;
			}
		}
	}
	cout << endl;
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
