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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	vector<pii> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i].ff>>a[i].ss;
	}
	int dist=0;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int x = abs(a[j].ff-a[i].ff);
			int y = abs(a[i].ss-a[j].ss);
			int t = x*x + y*y;
			dist = max(dist, t);
		}
	}
	double ans = sqrt(dist);
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(10);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
