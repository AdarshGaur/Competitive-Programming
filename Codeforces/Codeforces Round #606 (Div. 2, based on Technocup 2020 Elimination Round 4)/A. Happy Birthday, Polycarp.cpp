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
int const N = 1e9 + 7;

vector<pii> b;

void init(){
	int cnt=1, x=0;
	for(int i=0; i<10; i++){
		x = x*10 +1;
		for(int j=1; j<10; j++){
			b.push_back({x*j,cnt++});
		}
	}
}

void solve(){
	int n;cin>>n;
	int ans=1;
	for(auto [u,v]: b){
		if(u > n){
			break;
		}
		ans = v;
	}
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    init();
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
