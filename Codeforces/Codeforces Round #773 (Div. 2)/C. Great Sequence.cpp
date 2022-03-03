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


void solve(){
	int n, x;cin>>n>>x;
	multiset<int> a;
	for(int i=0; i<n; i++){
		int b;cin>>b;
		a.insert(b);
	}
	int ans=0;
	for(auto i: a){
		if( a.find(i*x) == a.end()){
			ans++;
		}else{
			a.erase(a.find(i*x));
		}
	}
	cout<<ans<<endl;
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
