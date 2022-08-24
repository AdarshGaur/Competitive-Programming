// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n;cin>>n;
	vector<int> dp(n+1, 1e9);
	dp[0]=0;
	for(int i=1; i<=n; i++){
		for(int j=i; j>0; j/=10){
			dp[i] = min(dp[i], dp[i-(j%10)]+1);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
