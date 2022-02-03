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
//int const mod = 998244353;
//int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int h,w;
	cin>>h>>w;
	vector<string> mt(h);
	for(int i=0; i<h; i++){
		cin>>mt[i];
	}
	h--, w--;
	vector<vector<pii>> dp(h+1, vector<pii>(w+1, {-INF,-INF}));
	dp[h][w] = {0,0};
	for(int i=w; i>0; i--){
		dp[h][i-1].ff = dp[h][i].ss;
		dp[h][i-1].ss = dp[h][i].ff;
		if(mt[h][i]=='-'){
			dp[h][i-1].ff--;
		}else{
			dp[h][i-1].ff++;
		}
	}
	for(int i=h; i>0; i--){
		dp[i-1][w].ff = dp[i][w].ss;
		dp[i-1][w].ss = dp[i][w].ff;
		if(mt[i][w] == '-'){
			dp[i-1][w].ff--;
		}else{
			dp[i-1][w].ff++;
		}
	}
	for(int i=h-1; i>=0; i--){
		for(int j=w-1; j>=0; j--){
			int x = dp[i+1][j].ss + (mt[i+1][j]=='-'?-1:1);
			int y = dp[i][j+1].ss + (mt[i][j+1]=='-'?-1:1);
			int d1 = x - dp[i+1][j].ff;
			int d2 = y - dp[i][j+1].ff;
			if(d1 > d2){
				dp[i][j].ff = x;
				dp[i][j].ss = dp[i+1][j].ff;
			}else{
				dp[i][j].ff = y;
				dp[i][j].ss = dp[i][j+1].ff;
			}
			// cout<<i<<" "<<j<<" "<<dp[i][j].ff<<" "<<dp[i][j].ss<<endl;
		}
	}
	if(dp[0][0].ff > dp[0][0].ss){
		cout<<"Takahashi"<<endl;
	}else if(dp[0][0].ff < dp[0][0].ss){
		cout<<"Aoki"<<endl;
	}else{
		cout<<"Draw"<<endl;
	}
	return 0;
}
