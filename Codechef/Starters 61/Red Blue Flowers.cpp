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
int const N = 2e4 +7;


void solve(){
	int n;
	cin >> n;
	
	int r[n], b[n];
	for(int i=0; i<n; i++)
		cin >> r[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	
	int dp[n][N];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = b[0];
	dp[0][r[0]] = 0;
	for(int i=0; i<n-1; i++){
		for(int j = 0; j < N; j++){
			if(dp[i][j] != -1){
				dp[i+1][j] = max(dp[i+1][j], dp[i][j] + b[i+1]); // take blue
				assert(j + r[i+1] < N);
				dp[i+1][j + r[i+1]] = max(dp[i+1][j + r[i+1]], dp[i][j]); // take red
			}
		}
	}
	
	int ans = 0;
	for(int j=0; j<N; j++){
		if(dp[n-1][j] != -1)
			ans = max(ans, min(dp[n-1][j], j));
	}
	cout << ans << endl;
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
