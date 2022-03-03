// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

double const PI = acos(-1);


void solve(){
	int n=3;
	pii a[n];
	for(int i=0; i<3; i++){
		cin>>a[i].second>>a[i].first;
	}
	sort(a, a+n);
	if(a[2].first == a[1].first){
		cout<<abs(a[2].second - a[1].second)<<endl;
	}else{
		cout<<0<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
