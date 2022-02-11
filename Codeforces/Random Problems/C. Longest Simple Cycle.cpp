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
	int n;cin>>n;
	int c[n], a[n], b[n];
	for(int &i:c)cin>>i;
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	int dp[n];
	dp[n-1] = c[n-1]-1;
	int ans=0;
	for(int i=n-1; i>0; i--){
		int parts = min(a[i],b[i])-1 + c[i-1] - max(a[i], b[i]);
		if(a[i]==b[i]){
			dp[i-1] = c[i-1]-1;
		}else{
			dp[i-1] = max(c[i-1]-1, dp[i]+2+parts);
		}
		ans = max(ans, dp[i]+2+abs(a[i]-b[i]));
	}
	cout<<ans<<endl;
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
