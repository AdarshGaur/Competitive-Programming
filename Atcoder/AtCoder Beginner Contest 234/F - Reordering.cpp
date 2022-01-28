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

int const INF = 2e18;
//int const mod = 1e9 +7;
int const mod = 998244353;
int const N = 50007;

int fact[N], finv[N];

void init(){
	fact[0] = 1;
	finv[0] = finv[1] = 1;
	for(int i=1; i<N; i++)
		fact[i] = (fact[i-1]*i)%mod;
	for(int i=2; i<N; i++)
		finv[i] = (mod- mod/i)* finv[mod%i]%mod;
	for(int i=1; i<N; i++)
		finv[i] = (finv[i-1]*finv[i])%mod;
}

int nCr(int n, int r){
	if(r==0)return 1;
	if(n<r or n<0)return 0;
	return ( (fact[n]*finv[r])%mod *finv[n-r])%mod;
}
	

void solve(){
	string s;cin>>s;
	int n = s.size();
	int freq[26]={0};
	for(auto i :s)
		freq[i-'a']++;
	vector<vi> dp(27, vi(n+1));
	dp[0][0]=1;
	for(int i=0; i<26; i++){
		for(int j=0; j<=n; j++){
			for(int k=0; k<=min(j,freq[i]); k++){
				dp[i+1][j] += dp[i][j-k] * nCr(j,k);
				dp[i+1][j] %= mod;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		ans += dp[26][i];
		ans %= mod;
	}
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    init();
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
