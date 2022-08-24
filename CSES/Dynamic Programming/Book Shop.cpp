// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	int n, x;cin>>n>>x;
	int cost[n], pages[n];
	for(int i=0; i<n; i++)cin>>cost[i];
	for(int i=0; i<n; i++)cin>>pages[i];
	int dp[n+1][x+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=x; j++){
			if(cost[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j-cost[i-1]]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[n][x]<<"\n";
	return 0;
}
