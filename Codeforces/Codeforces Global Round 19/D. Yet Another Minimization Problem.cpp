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
int const N = 1e4 + 7;


int solve(){
	int n;cin>>n;
	int a[n], b[n];
	int sum1=0, sum2=0;
	for(int &i:a){
		cin>>i;
		sum1 += i;
		sum2 += i*i;
	}
	for(int &i:b){
		cin>>i;
		sum1 += i;
		sum2 += i*i;
	}
	if(n==1)return 0;
	bool dp[n][N];
	memset(dp, false, sizeof(dp));
	dp[0][a[0]] = dp[0][b[0]] = true;
	for(int i=1; i<n; i++){
		for(int j=min(a[i],b[i]); j<N; j++){
			if(a[i] <= j){
				dp[i][j] = dp[i][j] or dp[i-1][j-a[i]];
			}
			if(b[i] <= j){
				dp[i][j] = dp[i][j] or dp[i-1][j-b[i]];
			}
		}
	}
	int ans = INF;
	for(int i=0; i<N; i++){
		if(dp[n-1][i]){
			int x =  i;
			int y = sum1-x;
			ans = min(ans, x*x + y*y);
		}
	}
	return (n-2)*sum2 + ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		cout<<solve()<<endl;
	return 0;
}
