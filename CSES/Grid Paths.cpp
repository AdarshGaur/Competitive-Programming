// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

int const mod = 1e9 +7;

int32_t main()
{
	int n;cin>>n;
	string s[n];
	for(int i=0; i<n; i++)
		cin>>s[i];
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	if(s[0][0]=='.')
		dp[0][0]=1;
	else
		dp[0][0]=0;
	for(int i=1; i<n; i++){
		if(s[0][i]=='*')
			dp[0][i] = 0;
		else
			dp[0][i] = dp[0][i-1];
		if(s[i][0] == '*')
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i-1][0];
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			if(s[i][j]!='*')
				dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
			else
				dp[i][j]=0;
		}
	}
	cout<<dp[n-1][n-1]<<endl;
	return 0;
}
