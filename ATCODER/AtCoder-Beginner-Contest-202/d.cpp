// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int mod = 1e9 +7;
//const int mod = 998244353;

int const N = 31;
int dp[N][N];
 
string solve(int a, int b, int k){
	if(a==0)return string(b,'b');
	if(b==0)return string(a, 'a');
	if(dp[a-1][b] >= k){
		return "a" + solve(a-1, b, k);
	}else{
		return "b" + solve(a, b-1, k-dp[a-1][b]);
	}
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    //
    dp[0][0]=0;
    for(int i=1; i<N; i++){
		dp[i][0]=1;
		dp[0][i]=1;
	}
	for(int i=1; i<N; i++){
		for(int j=1; j<N; j++){
			dp[i][j]=dp[i-1][j] + dp[i][j-1];
		}
	}
    int a, b, k;cin>>a>>b>>k;
    cout << solve(a,b,k)<<endl;
    return 0;
}
