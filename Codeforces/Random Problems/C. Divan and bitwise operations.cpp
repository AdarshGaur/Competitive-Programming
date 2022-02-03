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
//int const N = 1e5 + 7;

int modpow(int a, int b){
	a %= mod;
	int r =1;
	while(b){
		if(b&1){
			r = (r*a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return r;
}

void solve(){
	int n, m;cin>>n>>m;
	int Or=0;
	for(int i=0; i<m; i++){
		int l, r, x;
		cin>>l>>r>>x;
		Or |= x;
	}
	int x=1, cozz=0;
	for(int i=0; i<31; i++){
		if( Or & (x<<i) ){
			int t = (x<<i)%mod;
			cozz += (t*modpow(2,n-1))%mod;
		}
	}
	cout<<cozz%mod<<endl;
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
