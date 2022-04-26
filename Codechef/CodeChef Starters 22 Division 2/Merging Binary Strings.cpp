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
//int const mod = 998244353;
//int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	string a, b;
	cin>>a>>b;
	// Greedy approach will fail in this problem,
	int asuf[n+1]={0}, bsuf[n+1]={0};
	for(int i=n-1; i>=0; i--){
		asuf[i] = asuf[i+1] + (a[i]=='0');
		bsuf[i] = bsuf[i+1] + (b[i]=='0');
	}
	vector<vi> dp(n+1, vi(n+1, INF));
	dp[n][n] = 0;
	for(int i=n; i>=0; i--){
		for(int j=n; j>=0; j--){
			if(i<n){
				if(a[i]=='0'){
					dp[i][j] = min(dp[i][j], dp[i+1][j]);
				}else{
					dp[i][j] = min(dp[i][j], dp[i+1][j] + asuf[i]+bsuf[j]);
				}
			}
			if(j<n){
				if(b[j]=='0'){
					dp[i][j] = min(dp[i][j], dp[i][j+1]);
				}else{
					dp[i][j] = min(dp[i][j], dp[i][j+1]+asuf[i]+bsuf[j]);
				}
			}
		}
	}
	cout<<dp[0][0]<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
