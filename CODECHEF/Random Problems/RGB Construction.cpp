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


void solve(){
	int r,g,b;
	cin>>r>>g>>b;
	if(b > r+g){
		cout<<-1<<endl;
		return;
	}
	vector<pii> edges{{1,2}};
	string ans = "GR";
	r--, g--;
	int cur=3;
	while(r--){
		ans += "R";
		edges.push_back({1,cur++});
	}
	while(g--){
		ans += "G";
		edges.push_back({2,cur++});
	}
	int start=1;
	while(b--){
		ans += "B";
		edges.push_back({start++, cur++});
	}
	cout<<ans<<endl;
	for(auto [u,v]: edges){
		cout<<u<<" "<<v<<endl;
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
