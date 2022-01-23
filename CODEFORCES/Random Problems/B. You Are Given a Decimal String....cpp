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

int const INF = 1000'000'000'000;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

int solve(string &s, int a, int b){
	int dp[10][10];
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			dp[i][j] = ((i+a)%10 == j or (i+b)%10 == j ? 1: INF);
		}
	}
	for(int k=0; k<10; k++){
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
	int ans=0;
	for(int k=1; k<ii(s.size()); k++){
		int x = dp[s[k-1]-'0'][s[k]-'0'];
		if(x==INF)return -1;
		ans += x-1;
	}
	return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    string s;cin>>s;
    for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout<< solve(s, i, j)<<" ";
		}
		cout<<endl;
	}
    return 0;
}
