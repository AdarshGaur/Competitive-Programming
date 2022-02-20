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
int const mod = 998244353;
int const MAX = 1000'007;

int modpow(int a, int b){
	int r =1;
	for(;b>0; b>>=1){
		if(b&1) r = (r*a)%mod;
		a = (a*a)%mod;
	}
	return r;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n; cin >> n;
	int n_1 = modpow(n, mod-2);
	int freq[MAX] = {0};
	vector<vi> a(n, vi());
	for(int i=0; i<n; i++){
		int k;cin>>k;
		for(int j=0; j<k; j++){
			int x;cin>>x;
			a[i].push_back(x);
			freq[x]++;
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		int k = a[i].size();
		int x=0;
		for(auto j: a[i]){
			x += freq[j];
		}
		x%=mod;
		x = (x*n_1)%mod;
		x = (x*modpow(k,mod-2))%mod;
		x = (x*n_1)%mod;
		ans += x;
	}
	cout<<ans%mod<<endl;
	return 0;
}
