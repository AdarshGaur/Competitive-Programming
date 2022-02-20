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
	int n, s;cin>>n>>s;
	int a[n];
	for(int &i:a)cin>>i;
	int nex=-1, mx=0, ans=0;
	for(int i=0; i<n; i++){
		s -= a[i];
		if(a[i] > mx){
			ans = i, mx = a[i];
		}
		if(s<0){
			nex=i;
			break;
		}
	}
	if(nex == -1){
		ans=-1;
	}
	cout<<ans+1<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		//cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
