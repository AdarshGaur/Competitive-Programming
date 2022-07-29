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
	
	int a[n];
	for(int &i: a)
		cin >> i;
	
	int dp1[n+1], dp2[n];
	dp1[0] = dp2[0] = dp2[1] = 0;
	dp1[1] = a[0];
	for(int i=2; i<=n; i++){
		dp1[i] = min(dp1[i-1] +a[i-1], dp1[i-2] +a[i-2]);
		if(i == n) break;
		dp2[i] = min(dp2[i-1] +a[i-1], dp2[i-2] +a[i-2]);
	}
	
	cout << min(dp1[n], dp2[n-1] +a[n-1]) << endl;
}

signed main()
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
