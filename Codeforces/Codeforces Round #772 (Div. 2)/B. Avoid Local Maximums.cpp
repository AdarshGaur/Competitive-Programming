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
	vi a(n);
	for(int &i:a)cin>>i;
	vi mxs(n, 0);
	for(int i=1; i<n-1; i++){
		if(a[i]>a[i+1] and a[i]>a[i-1]){
			mxs[i] = 1;
		}
	}
	for(int i=1; i<n-1; i++){
		if(mxs[i-1] == 1 and mxs[i+1]==1){
			mxs[i-1] = mxs[i+1] = 0;
			mxs[i] = -1;
		}
	}
	int cnt=0;
	for(int i=1; i<n-1; i++){
		if(mxs[i]!=0){
			a[i] = max(a[i-1], a[i+1]);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int &i:a){
		cout<<i<<" ";
	}
	cout<<endl;
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
