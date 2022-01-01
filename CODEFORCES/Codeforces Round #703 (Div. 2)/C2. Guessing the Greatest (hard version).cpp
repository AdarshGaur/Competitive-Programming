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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

map<pii, int> mp;

int ask(int l, int r){
	if(l>=r)return ii(-1);
	if(mp[{l,r}]!=0)return mp[{l,r}];
	cout<<"? "<<l<<" "<<r<<endl;
	cout.flush();
	int res;cin>>res;
	mp[{l,r}]=res;
	return res;
}

void solve(){
	int n;cin>>n;
	int l=1, r=n;
	int smax = ask(l, r);
	if(ask(l,smax) == smax){
		int ans=1;
		r=smax-1;
		while(l<=r){
			int mid = (l+r)/2;
			if( ask(mid, smax) == smax){
				ans = mid;
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		cout<<"! "<<ans<<endl;
		exit(0);
	}else{
		int ans = smax+1;
		l = smax+1;
		while(l<=r){
			int mid = (r+l)/2;
			if(ask(smax, mid) == smax){
				ans = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		cout<<"! "<<ans<<endl;
		exit(0);
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
