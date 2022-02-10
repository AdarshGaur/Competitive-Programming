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
int const N = 31;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int a, b, k;cin>>a>>b>>k;
	int dp[N][N];
	dp[0][0] = 0;
	for(int i=1; i<N; i++){
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	for(int i=1; i<N; i++){
		for(int j=1; j<N; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			
		}
	}
	string ans;
	while(k>0){
		if(a==0 or b==0)break;
		if(k > dp[a-1][b]){
			ans += 'b';
			k -= dp[a-1][b--];
		}else{
			ans += 'a';
			a--;
		}
	}
	ans += string(a, 'a');
	ans += string(b, 'b');
	cout<<ans<<endl;
	return 0;
}
