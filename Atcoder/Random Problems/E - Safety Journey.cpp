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
// int const mod = 1e9 +7;
int const mod = 998244353;
// int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m, k;
	cin>>n>>m>>k;
	vector<vi> g(n);
	for(int i=0; i<m; i++){
		int u, v;cin>>u>>v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vi dp(n, 0);
	dp[0]=1;
	for(int K=1; K<=k; K++){
		int sum=0;
		for(int i:dp){
			sum += i;
		}
		vi temp(n);
		for(int i=0; i<n; i++){
			int x = sum - dp[i];
			for(auto v : g[i]){
				x -= dp[v];
			}
			temp[i] = x%mod;
		}
		dp = temp;
	}
	cout<<dp[0]%mod<<endl;
	return 0;
}
