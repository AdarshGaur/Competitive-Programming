// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

void solve(){
	int n, k;cin>>n>>k;
	int a = n - k;
	for(int i=1; i < k-a; i++){
		cout<<i<<" ";
	}
	for(int j=k; j>=k-a; j--){
		cout<<j<<" ";
	}
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	// pre();
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
