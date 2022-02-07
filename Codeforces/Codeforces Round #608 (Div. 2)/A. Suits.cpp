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
	int a, b, c, d, e, f;
	cin>>a>>b>>c>>d>>e>>f;
	int ans=0;
	if(e>f){
		int l = min(d, a);
		d -= l;
		a -= l;
		ans += e*l;
		l = min({b,c,d});
		ans += f*l;
	}else{
		int l = min({b,c,d});
		d -= l;
		ans += f*l;
		l = min(d,a);
		ans += e*l;
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	while(test--)
		solve();
	return 0;
}
