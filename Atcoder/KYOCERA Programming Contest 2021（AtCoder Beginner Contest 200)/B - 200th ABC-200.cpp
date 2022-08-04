////////////////////////// Author : Adarsh Gaur ////////////////////////////

#include <bits/stdc++.h>
//#include <array>
//#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define forn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s,e) for(ll i = s; i >= e; i--)
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






int main()
{
    fast_cin();
    ll n, k;
    cin>>n>>k;
    while(k--){
        if(n%200==0){
            n/=200;
        }else{
            n*= 1000;
            n+=200;
        }
    }
    cout<<n;
    return 0;
}
