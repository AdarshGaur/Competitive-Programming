// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

const int N = 1e5 +7;
vector<vi> factors(N);
vector<bool> vis(N, false);
void sieve(){
	vis[0] = vis[1] = true;
	factors[1].push_back(1);
	for(int i=2; i<N; i++){
		if(!vis[i]){
			for(int j=i; j<N; j+=i){
				vis[j]=true;
				factors[j].push_back(i);
			}
		}
	}
}

int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	sieve();
    int n,ans=0;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int mx = 0;
		for(auto j: factors[a[i]]){
			mx = max(dp[j]+1, mx);
		}
		for(auto j: factors[a[i]]){
			dp[j] = mx;
		}
		ans = max(ans, mx);
	}cout<<ans<<endl;
    return 0;
}
