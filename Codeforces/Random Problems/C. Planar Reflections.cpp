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
int const N = 1e3 + 7;
int n, k;

int dp[N][N][2];

int get(int slit, int age, int dir){
	if(age==1)return 1;
	if(dp[slit][age][dir]!=-1)return dp[slit][age][dir];
	int ans=2;
	if(dir==1){
		if(slit < n){
			ans += get(slit+1, age, dir)-1;
		}
		if(slit > 1){
			ans += get(slit-1, age-1, 0)-1;
		}
	}else{
		if(slit > 1){
			ans += get(slit-1, age, dir)-1;
		}
		if(slit < n){
			ans += get(slit+1, age-1, 1)-1;
		}
	}
	return dp[slit][age][dir] = ans%mod;
}

void solve(){
	cin>>n>>k;
	memset(dp, -1, sizeof(dp));
	cout << get(1, k, 1) <<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
