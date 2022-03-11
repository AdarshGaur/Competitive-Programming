/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; ++i)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second


/////// Main Logical code starts from here ////////

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
	cout<<modpow(n,k)<<endl;
}

signed main()
{
    fast_io;
    cout.precision(20);
    int times;cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
