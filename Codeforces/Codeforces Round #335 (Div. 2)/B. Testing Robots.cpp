// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)

//int const INF = 2e18;
//int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int x, y, x0, y0;
	string s;
	cin>>x>>y>>x0>>y0>>s;
	vector<vector<bool>> vis(x+1, vector<bool>(y+1, false));
	cout<<1<<" ";
	vis[x0][y0]=true;
	int n = s.size()-1, cnt=1;
	for(int i=0; i<n; i++){
		if(s[i]=='L'){
			y0 = max(1, y0-1);
		}else if(s[i]=='R'){
			y0 = min(y, y0+1);
		}else if(s[i]=='U'){
			x0 = max(1, x0-1);
		}else{
			x0 = min(x, x0+1);
		}
		if(vis[x0][y0]){
			cout<<"0 ";
		}else{
			cout<<"1 ";
			vis[x0][y0]=true;
			cnt++;
		}
	}
	cout<<x*y -cnt<<endl;
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
