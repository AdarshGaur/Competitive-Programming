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


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, p;
	cin>>n>>p;
	int a[n];
	for(int &i:a)cin>>i;
	sort(a, a+n);
	set<int> reduced;
	for(int i:a){
		int t = i;
		bool ok=true;
		while((t>2 and t%2==1) or (t>=4 and t%4==0)){
			if(t%4==0){
				t/=4;
			}else if(t%2==0){
				break;
			}else{
				t--;
				t/=2;
			}
			if(reduced.find(t) != reduced.end()){
				ok=false;
				break;
			}
		}
		if(ok)reduced.insert(i);
	}
	cerr<<reduced.size()<<endl;
	int dp[p]={0};
	for(auto r:reduced){
		int m=0;
		while(r>0){
			m++, r>>=1;
		}
		if(m<=p)dp[m-1]++;
	}
	int ans=0;
	for(int i=0; i<p; i++){
		if(i>=1){
			dp[i] += dp[i-1];
		}
		if(i>=2){
			dp[i] += dp[i-2];
		}
		dp[i] %= mod;
		ans += dp[i];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
