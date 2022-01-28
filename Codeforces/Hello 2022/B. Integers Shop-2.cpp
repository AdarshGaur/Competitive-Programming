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
	map<pii,int> mp;
	int mx=0, mxc=INF, mn=INF, mnc=INF;
	for(int i=0; i<n; i++){
		int l, r, c;
		cin>>l>>r>>c;
		pii pp = {l,r};
		if(mp.count(pp)==0){
			mp[pp] = c;
		}else{
			mp[pp] = min(mp[pp], c);
		}
		if(l <= mn){
			if(l<mn)
				mnc=INF;
			mn = l;
			mnc = min(mnc, c);
		}
		if(r >= mx){
			if(r>mx)
				mxc=INF;
			mx = r;
			mxc = min(mxc, c);
		}
		int ans = mxc + mnc;
		if(mp.count({mn,mx}) == 1){
			ans = min(mp[{mn,mx}],ans);
		}
		cout<<ans<<endl;
	}
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
