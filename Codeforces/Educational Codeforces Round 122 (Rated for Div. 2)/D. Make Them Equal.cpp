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
//int const mod = 998244353;
int const N = 1e3 + 7;

vi pp(N, INF);

void init(){
	pp[0] = pp[1] = 0;
	int mx=0;
	for(int i=1; i<N; i++){
		for(int j=1; j <=i; j++){
			int k = i + i/j;
			if(k < N)pp[k] = min(pp[k], pp[i]+1);
		}
		mx = max(mx, pp[i]);
	}
	aster(mx);
}

void solve(){
	int n, k;cin>>n>>k;
	int opt[n], c[n];
	for(int i=0; i<n; i++){
		int x;cin>>x;
		opt[i] = pp[x];
	}
	for(auto &i: c)cin>>i;
	k = min(15*n, k);
	vi dp(k+1, -INF);
	dp[0] = 0;
	for(int i=0; i<n; i++){
		int coin = c[i], ops = opt[i];
		for(int j=k; j>=0; j--){
			if(ops + j <= k){
				dp[j + ops] = max(dp[j+ops], dp[j]+coin);
			}
		}
	}
	int mx =-1;
	for(int i:dp)mx = max(mx, i);
	cout<<mx<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	init();
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
