// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, m;cin>>n>>m;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int dp[n][m+1]; // dp[i][j] = no. of ways value j can be present at index i
	memset(dp, 0, sizeof(dp));
	if(a[0]==0){
		for(int i=1; i<=m; i++)dp[0][i]=1;
	}else{
		dp[0][a[0]]=1;
	}
	for(int i=1; i<n; i++){
		if(a[i]==0){
			for(int j=1; j<=m; j++){
				int x=j-1, y=j+1;
				if(x>=1)dp[i][j] += dp[i-1][x];
				if(y<=m)dp[i][j] += dp[i-1][y];
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= mod;
			}
		}else{
			int j = a[i];
			int x = j-1, y=j+1;
			if(x>=1)dp[i][j] += dp[i-1][x];
			if(y<=m)dp[i][j] += dp[i-1][y];
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= mod;
		}
	}
	int ans=0;
	for(int i=1; i<=m; i++)
		ans += dp[n-1][i];
	cout<<ans%mod<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	while(test--)
		solve();
	return 0;
}
