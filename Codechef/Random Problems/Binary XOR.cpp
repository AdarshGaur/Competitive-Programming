////////////////////////// Author : Adarsh Gaur ////////////////////////////

#include <bits/stdc++.h>
//#include <array>
//#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpi;
typedef vector<pii> vpii;
#define forn(i,s,e) for(int i = s; i < e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////////////////////// Main functions start from here ///////////////////////


const int MAXN = 1e6 + 5;
const long long mod = 1e9 + 7;

//pre-compute factorial values
unsigned long long f[MAXN];
unsigned long long invf[MAXN];
void factorial(){
   //factorials % mod
   f[0]=1;
   invf[0]=invf[1]=1;
   for(int i=1; i<=MAXN; i++){
       f[i]=(f[i-1]*i)%mod;
    }
    forn(i, 2, MAXN){
         invf[i] = (mod - mod/i) * invf[mod % i] % mod;
    }
    forn(i,1,MAXN){
         invf[i] = (invf[i-1] * invf[i])%mod;
    }
}


// To calculates a^x mod m in logarithmic time O(logx).
unsigned long long modPow(unsigned long long a, int x, int m) {
   unsigned long long res = 1;
   a=a%m;
   while(x > 0) {
      if( x & 1) {
           res = (res * a) % m;
       }
       a = (a * a) % m;
       x = x >> 1; // x=x/2;
   }
   return res;
}


/////nCr using fermat little theroem in O(1) ( yeah finding factorials and inverse factorials took the main time here as O(N)
unsigned long long nCr_using_Fermet(unsigned long long n, long long r, long long m){
   //base Case
   if(r==0){
      return 1;
   }
   if(n<r){
      return 0;
   }
   long long res = (f[n] * invf[r])%m;
   return  (res * invf[n-r])%m ;
   //return (f[n] * modInverse(f[r], m) % m * modInverse(f[n-r],m) %m) %m;
}




void solve(){
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    int cnta=0, cntb=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            cnta++;
        }
        if(b[i]=='1'){
            cntb++;
        }
    }
    int pmin = abs(cnta-cntb);
    int pmax = cnta + cntb;
    int temp=0;
    if(pmax >n){
        temp = pmax - n ;
        pmax -= 2*temp;
    }
    int ans=0;
    for(int i=pmin; i<=pmax; i+=2){
        ans += nCr_using_Fermet(n,i,mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}

signed main()
{
    fast_cin();
    factorial();
    int it;cin >> it;
    while(it--){
    //cout << "Case #" << it+1 << ": ";
    solve();
    }
    return 0;
}