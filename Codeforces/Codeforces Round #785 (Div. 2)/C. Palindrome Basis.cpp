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
int const N = 40007;
int const N2 = 500;

vector<int> palins;
int dp[N][N2];
int ans[N];

bool isPalin(int x){
	int a = 0, n = x;
	while(x != 0){
		a = a*10 + x%10;
		x /= 10;
	}
	return a == n;
}

void pre(){
	// find all the palindromic numbers
	for(int i=0; i<N; i++){
		if(isPalin(i)){
			palins.push_back(i);
		}
	}
	
	// use those numbers to find the rest
	int n = palins.size();
	
	for(int i=0; i<n; i++){
		dp[0][i] = 1;
	}
	
	for(int i=1; i<N; i++){
		dp[i][0] = 0;
		for(int j=1; j<n; j++){
			dp[i][j] = dp[i][j-1];
			if(palins[j] <= i)
				dp[i][j] += dp[i - palins[j]][j];
			dp[i][j] %= mod;
		}
		ans[i] = dp[i][n-1];
	}
}

void solve(){
	int n;
	cin >> n;
	cout << ans[n] << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	
	pre();

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
