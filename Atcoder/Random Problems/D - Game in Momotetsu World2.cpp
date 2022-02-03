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
	int dp[h][w];
	h--, w--;
	for(int i=h; i>=0; i--){
		for(int j=w; j>=0; j--){
			dp[i][j] = -INF;
			dp[h][w] = 0;
			if(i+1 <= h){
				dp[i][j] = max(dp[i][j], (mt[i+1][j]=='-'?-1:1) - dp[i+1][j]);
			}
			if(j+1 <= w ){
				dp[i][j] = max(dp[i][j], (mt[i][j+1]=='-'?-1:1) - dp[i][j+1]);
			}
		}
	}
	if(dp[0][0] > 0){
		cout<<"Takahashi"<<endl;
	}else if(dp[0][0] < 0){
		cout<<"Aoki"<<endl;
	}else{
		cout<<"Draw"<<endl;
	}
	return 0;
}
