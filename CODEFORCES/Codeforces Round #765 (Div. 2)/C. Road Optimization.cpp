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


//bool comp(pii c, pii b){
	//if(c.ff == b.ff){
		//int i=c.ss, j=b.ss;
		//int x = a[i]*(d[i+1]-d[i]);
		//int y = a[j]*(d[j+1]-d[j]);
		//while( i>=0 and j>=0 and x == y){
			//i--,j--;
			//x = a[i]*(d[i+1]-d[i]);
			//y = a[j]*(d[j+1]-d[j]);
		//}
		//if(x <= y){
			//return false;
		//}
		//return true;
	//}
	//return c.ff > b.ff;
//}

void solve(){
	int n, l, k;
	cin>>n>>l>>k;
	int d[n+1], a[n+1];
	for(int i=0; i<n; i++)
		cin>>d[i];
	for(int i=0; i<n; i++)
		cin>>a[i];
	d[n]=l;
	a[n]=0;
	vector<vi> dp(n+1, vi(k+1,INF));
	dp[0][0]=0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=k; j++){
			for(int q=i-1; q>=0; q--){
				int x = j - (i-1-q);
				if(x<0)continue;
				dp[i][j] = min(dp[i][j], dp[q][x] + a[q]*(d[i]-d[q]));
			}
		}
	}
	int ans=INF;
	for(int i=0; i<=k; i++){
		ans = min(ans, dp[n][i]);
	}
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
