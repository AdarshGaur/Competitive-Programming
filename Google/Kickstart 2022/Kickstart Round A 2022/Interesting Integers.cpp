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
int const mod = 1e9 +7;
// int const mod = 998244353;
int const N = 1e5 + 7;

int dp[N];

void pre(){
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<N; i++){
		dp[i] = dp[i-1];
		int x = i;
		int s =0, p = 1;
		while(x){
			int t = x%10;
			s += t;
			p *= t;
			x /= 10;
		}
		if( p % s == 0)dp[i]++;
	}
}

int solve(){
	int a, b;
	cin >> a >> b;
	// only for b less than 1e5;
	return dp[b] - dp[a-1];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	pre();
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		cout<<"Case #"<<t<<": " << solve() << endl;
	}
	return 0;
}
