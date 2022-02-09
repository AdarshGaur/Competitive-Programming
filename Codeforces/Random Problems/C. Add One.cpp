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
int const N = 2e5 + 7;

int dp[N];

void init(){
	dp[9]=3;
	for(int j=0; j<N; j++){
		if(j>9){
			dp[j] = dp[j-9] + dp[j-10];
			dp[j] %= mod;
		}else if(j<9){
			dp[j] = 2;
		}
	}
}

void solve(){
	string n;
	int m;
	cin>>n>>m;
	int ans =0;
	for(auto i: n){
		int x = 10 - (i-'0');
		x = m-x;
		if(x<0){
			ans += 1;
		}else{
			ans += dp[x];
		}
		ans %= mod;
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	init();
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
