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



// simple sieve
//// sieve in strictly less than O(nloglogn) time and takes O(n) memory.
const int MAXN = 1e7+1;
vector<bool> isPrime(MAXN, true);        //isPrime[i] = true indicates i is prime.
vi primes;

void sieve(){
   //if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
   isPrime[0] = isPrime[1] = false;
   for(int i = 3; i*i <= MAXN; i+=2){
        if(isPrime[i]){
            // primes.pb(i);
           if(i*(int)1*i <= MAXN){
               for(int j = i*i; j <= MAXN; j += (2*i)){
                   isPrime[j] = false;
               }
           }
       }
    }
    for(int i=3; i<MAXN; i+=2){
        if(isPrime[i]==true){
            primes.pb(i);
        }
    }
}

vi ans(MAXN,0);

void pre(){
    ans[2]=1;
    for(int i=0;i<primes.size();i++){
        ans[primes[i]]=1;
        if(primes[i]*2<MAXN){
            ans[primes[i]*2]=-1;
        }
    }
    for(int i=3;i<MAXN; i++){
        ans[i]+=ans[i-1];
    }
}



signed main()
{
    fast_cin();
    sieve();
    pre();
    int it;cin >> it;
    while(it--){
        int n;cin>>n;
        cout<<ans[n]<<endl;
    }
    
    return 0;
}