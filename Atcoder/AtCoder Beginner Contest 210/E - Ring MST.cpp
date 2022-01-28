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
	int n, m;cin>>n>>m;
	vector<pii> ac;
	for(int i=0; i<m; i++){
		pii a;
		cin>>a.ss>>a.ff;
		ac.push_back(a);
	}
	sort(ac.begin(), ac.end());
	int x = n, last = n;
	int ans = 0;
	for(int i=0; i<m; i++){
		x = __gcd(x, ac[i].ss);
		ans += ac[i].ff * (last - x);
		last = x;
	}
	if(last>1)ans=-1;
	cout<<ans<<endl;
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
