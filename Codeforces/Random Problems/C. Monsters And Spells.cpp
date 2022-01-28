// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second
#define max(a,b) max<int>(a,b)
#define min(a,b) min<int>(a,b)

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	int k[n], h[n];
	for(int i=0; i<n; i++)cin>>k[i];
	for(int i=0; i<n; i++)cin>>h[i];
	vector<pii> intervals;
	for(int i=0; i<n; i++){
		intervals.push_back({k[i]-h[i], k[i]});
	}
	sort(intervals.begin(), intervals.end());
	int ans=0, l=0, r=0;
	for(auto [u,v]: intervals){
		if(u >= r){
			ans += (r-l)*(r-l+1)/2;
			l = u;
			r = v;
		}else{
			r = max(r,v);
		}
	}
	ans += (r-l+1)*(r-l)/2;
	cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
