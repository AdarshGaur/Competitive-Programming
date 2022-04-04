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


signed main()
{
    fast_cin();
    int n;cin >> n;
    int arr[n];
    forn(i,0,n){
        cin>>arr[i];
    }

    vector<bool> isprime(101,true);
    vi prime_factors;
    forn(i,2,101){
        if(isprime[i]){
            prime_factors.pb(i);
            for(int j=i; j<101; j+=i){
                isprime[j]=false;
            }
        }
    }
    int plen = prime_factors.size();
    vector<vi> prefix(n+1,vector<int>(plen,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<plen;j++){
            // if(arr[i]%prime_factors[j]==0){
                while(arr[i-1]%prime_factors[j]==0){
                    prefix[i][j]++;
                    arr[i-1]/=prime_factors[j];
                }
                prefix[i][j]+=prefix[i-1][j];
            // }
        }
    }
    /// so now the right prefix is ready

    int t;cin>>t;
    while(t--){
        int l,r,m;
        cin>>l>>r>>m;
        int ans=1;
        for(int i=0;i<plen;i++){
            ans = (ans * modPow(prime_factors[i],prefix[r][i]-prefix[l-1][i],m))%m;
        }
        cout<<ans%m<<endl;
    }
    
    return 0;
}