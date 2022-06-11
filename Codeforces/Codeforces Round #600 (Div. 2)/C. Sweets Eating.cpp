/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
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
#define ff first
#define ss second


#ifndef ONLINE_JUDGE
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#else
#define aster(x)
#endif


/////// Main Logical code starts from here ////////

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n,m;cin>>n>>m;
	vi a(n), pref(n);
	fore(i,0,n){
		cin>>a[i];
	}
	sort(all(a));
	pref[0]=a[0];
	fore(i,1,n){
		pref[i] = pref[i-1]+a[i];
	}
	fore(i,0,n){
		if(i<m){
			cout<<pref[i]<<" ";
		}else{
			pref[i] += pref[i-m];
			cout<<pref[i]<<" ";
		}
	}
	cout<<endl;
}

int32_t main()
{
    fast_io;
    cout.precision(20);
    //int times;cin >> times;
    //for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    //}
    return 0;
}
