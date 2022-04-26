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
const long long MAXN = 1e5+2;
vector<int> isPrime(MAXN, 0);        //isPrime[i] = 0 indicates i is prime.
// vi result(MAXN);
// vvi kprimes(1e5+1, vector<int>());

void sieve(){
    for(long long i = 2; i<= MAXN; i++){
        if(isPrime[i]==0){
            for(long long j = 2*i; j<=MAXN; j+=i){
                isPrime[j]++;
            }
            isPrime[i]=1;
        }
    }
    // for(int i=2; i<=MAXN; i++){
    //     result[i]=kprimes[i].size();
    // }
}




void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    int cnt=0;
    for(int i=a;i<=b;i++){
        if(isPrime[i]==k){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

signed main()
{
    fast_cin();
    sieve();
    int it;cin >> it;
    while(it--){
    //cout << "Case #" << it+1 << ": ";
    solve();
    }
    
    return 0;
}