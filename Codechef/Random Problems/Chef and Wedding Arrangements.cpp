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

int const INF = 2e12;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, k;cin>>n>>k;
	int f[n];
	for(int i=0; i<n; i++){
		cin>>f[i];
	}
	int dp[n+1], cnt[101];
	fill(dp, dp+n+1, INF);
	dp[0] = 0;
	for(int i=0; i<n; i++){
		memset(cnt, 0, sizeof(cnt));
		for(int j=i; j<n; j++){
			cnt[f[j]]++;
			int ans=0;
			//cnt of conflicts
			for(int p=1; p<101; p++){
				ans += (cnt[p]<=1?0:cnt[p]);
			}
			dp[j+1] = min(dp[i]+k+ans, dp[j+1]);
		}
	}
	cout<<dp[n]<<endl;
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
