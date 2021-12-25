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

const int N = 1e6 + 1;
const long long mod = 1e9 + 7;

 
//pre-computed factorial values
unsigned long long f[N];
void fact(int n, long long m){        ///////   DON'T FORGET TO CALL THIS FACT FUNCTION ////////// 
   //factorials mod m
   f[0]=1;
   for(int i=1; i<=n; i++){
       f[i]=(f[i-1]*i)%m;
    }
}
 
 
// To calculates a^x mod m in logarithmic time O(logx).
unsigned long long modPow(unsigned long long a, int x, long long int m) {
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
 
 
unsigned long long modInverse(unsigned long long a,long long m){
    return modPow(a,m-2,m);
}
 
 
unsigned long long chooseMod(unsigned long long n, long long r, long long m){
   //base Case
   if(r==0){
      return 1;
   }
   if(n<r){
      return 0;
   }
   return (f[n] * modInverse(f[r], m) % m * modInverse(f[n-r],m) %m) %m;
}
 



void solve(ll n){
    ll a, b, d;
    cin>>a>>b>>d;
    ll res = chooseMod(n, a, mod);
    ll t = chooseMod(b, d, mod);
    res = (res * modPow(t, a, mod))%mod;
    cout<<res<<endl;
}

int main()
{
    fast_cin();
    fact(N, mod);
    ll n;
    while(cin>>n){
     //cout << "Case #" << it+1 << ": ";
        solve(n); 
    }
    return 0;
}