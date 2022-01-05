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
	vi l(n), r(n), c(n);
	for(int i=0; i<n; i++){
		cin>>l[i]>>r[i]>>c[i];
	}
	int cost[n]={0};
	int start=INF, end=0, sc=INF, ec=INF, mxlen=0, lc=INF;
	for(int i=0; i<n; i++){
		if(l[i]<start){
			start = l[i];
			sc = c[i];
		}else if(l[i]==start){
			sc = min(sc, c[i]);
		}
		if(r[i]>end){
			end = r[i];
			ec = c[i];
		}else if(r[i]==end){
			ec = min(ec, c[i]);
		}
		if(mxlen < r[i]-l[i]+1){
			mxlen = r[i]-l[i]+1;
			lc = c[i];
		}else if(mxlen == r[i]-l[i]+1){
			lc = min(lc, c[i]);
		}
		cost[i] = ec +sc;
		if(mxlen == end-start+1){
			cost[i] = min(lc, cost[i]);
		}
	}
	for(auto i:cost){
		cout<<i<<endl;
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
