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

//const int INF = 2e18;
const int N = 1e6 +7; //// check the constraints
//const int mod = 1e9 +7;
//const int mod = 998244353;


vector<bool> isprime(N, true);	
void sieve(){
	isprime[0] = isprime[1] = false;
	for(int i=2; i*i < N; i++){
		if(isprime[i]){
			for(int j=i*i; j < N; j+=i){
				isprime[j]=false;
			}
		}
	}
}

void solve(){
	int n, e;
	cin>>n>>e;
	vi a(n);
	for(int i=0; i<n; i++)cin>>a[i];
	vi dp(n), upcoming(n), ans(n);
	int ex= e;
	for(int i=n-1; i>=0 and ex>=0; i--, ex--){
		dp[i]=0;
		upcoming[i] = i;
		ans[i] = 0;
	}
	for(int i=n-e-1; i>=0; i--){
		if(a[i]!=1){
			dp[i] = dp[i+e] - dp[upcoming[i+e]];
			if(a[upcoming[i+e]]==1)dp[i]++;
			upcoming[i] = i;
			ans[i] = dp[i];
		}else{
			dp[i] = dp[i+e]+1;
			upcoming[i] = upcoming[i+e];
			ans[i] = ans[upcoming[i]]+1;
		}
		if(!isprime[a[upcoming[i]]])ans[i]=0;
	}
	int sum=0;
	for(auto i:ans){
		sum+=i;
	}
	cout<<sum<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	sieve();
    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
