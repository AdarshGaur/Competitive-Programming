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

int modpow(int a, int b){
  int r =1;
  while(b){
    if(b &1){
      r *= a;
      r %= mod;
    }
    a *= a;
    a %= mod;
    b >>=1;
  }
  return r;
}

void solve(){
	int n, k;cin>>n>>k;
	int ans =0;
	for(int i=0; i<30; i++){
		if(k & (1<<i)){
			ans = (ans + modpow(n,i))%mod;
		}
	}
	cout<<ans<<endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int times=1;
	cin >> times;
	for(int i=1;i<=times; ++i){
		//cout<<"Case #"<< i << ": ";
		solve();
	}
	return 0;
}
