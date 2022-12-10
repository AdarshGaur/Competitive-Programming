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
	int n;
	cin >> n;
	
	map<int,int> mp;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	
	int zero = 0, equal = 0, ans = 0;
	for(auto &[u, v]: mp){
		if(u == 0){
			zero++;
			continue;
		}
		if(v > 1){
			equal++;
		}
		ans += v;
	}
	
	if(zero or equal){
		cout << ans << endl;
	}else{
		cout << n+1 << endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}