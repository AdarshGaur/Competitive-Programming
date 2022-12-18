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
	int x[3], y[3];
	for(int i=0; i<3; i++){
		cin >> x[i] >> y[i];
	}
	
	bool pos = false;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i == j or i == k or j == k) continue;
				int mnx = min({x[i], x[j], x[k]});
				int mny = min({y[i], y[j], y[k]});
				int mxx = max({x[i], x[j], x[k]});
				int mxy = max({y[i], y[j], y[k]});
				if(mnx < x[i] and mxx > x[i]) pos = true;
				if(mny < y[i] and mxy > y[i]) pos = true;
			}
		}
	}
	
	cout << ( pos ? "YES" : "NO") << endl;
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
