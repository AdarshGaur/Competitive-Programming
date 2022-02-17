// Author : Adarsh Gaur 
#include <bits/stdc++.h>
using namespace std;

int const mod = 1e9 +7;
int const N = 1e6 +7;
long long dp[N][2];

void pre(){
	dp[1][0] = dp[1][1] = 1;
	for(int i=2; i<N; i++){
		dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1])%mod;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2)%mod;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	pre();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<(dp[n][0]+dp[n][1])%mod<<"\n";
	}
	return 0;
}
