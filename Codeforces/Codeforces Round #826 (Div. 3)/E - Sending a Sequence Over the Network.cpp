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
	
	int b[n+1];
	b[0] = 0;
	for(int i=1; i<=n; i++){
		cin >> b[i];
	}
	
	vector<bool> dp(n+1, false);
	dp[0] = true;
	for(int i=1; i<=n; i++){
		int prev = i - b[i] -1, next = i + b[i];
		if(prev >= 0 and i != 1) dp[i] = dp[i] or dp[prev];
		if(next <= n and i != n) dp[next] = dp[next] or dp[i-1];
	}
	
	cout << (dp[n] ? "YES" : "NO") << endl;
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
