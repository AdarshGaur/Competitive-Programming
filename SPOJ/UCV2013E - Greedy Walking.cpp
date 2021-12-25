#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
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
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s,e) for(ll i = s; i >= e; i--)
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
const long long mod = 1e9 +7;
const int N = 1e4 +1;
 
//pre-computed factorial values
unsigned long long f[N];
unsigned long long invf[N];
void fact(int n, long long m){
   f[0]=invf[0]=invf[1]=1;
   for(int i=1; i<=n; i++){
       f[i]=(f[i-1]*i)%m;
    }
    forn(i, 2, n){
        invf[i] = (m - m/i) * invf[m % i] % m;
    }
	forn(i,1,n){
        invf[i] = (invf[i-1] * invf[i])%m;
    }
}


void solve(ll n){
    ll temp=0, ans=0;
    ll arr[n], brr[n];
    forn(i, 0, n){
        cin>>arr[i];
    }
    forn(i, 0, n){
        cin>>brr[i];
        temp+=brr[i]-arr[i];
    }
    ans = f[temp];
    forn(i, 0, n){
        temp=brr[i]-arr[i];
        ans = (ans * invf[temp])%mod;
    }
    cout<<ans<<endl;
}

int main()
{
    fast_cin();
    fact(N, mod);
    ll t;
    while(cin>>t){
     //cout << "Case #" << it+1 << ": ";
        if(t==0){
            break;
        }
        solve(t);
    }
    return 0;
}