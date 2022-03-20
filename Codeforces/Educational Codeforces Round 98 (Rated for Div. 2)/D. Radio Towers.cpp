// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 998244353;

int modpow(int a, int b){
	a %= mod;
	int r = 1;
	while(b){
		if(b&1)r = (r * a)%mod;
		a = (a * a)%mod;
		b >>= 1;
	}
	return r;
}

void solve(){
	int n;
	cin >> n;
	int dp[n];
	dp[0] = dp[1] = 1;
	int odd = 1, even = 1;
	for(int i=2; i<=n; i++){
		if(i&1){
			dp[i] = even;
			odd += dp[i];
		}else{
			dp[i] = odd;
			even += dp[i];
		}
		dp[i] %= mod;
		odd %= mod;
		even %= mod;
	}
	int t = modpow(2, n);
	cout << (dp[n] * modpow(t, mod-2)) % mod<< endl;
}

int32_t main()
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
