// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "debug.h"
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int ans[n] = {};
	set<int> s(a, a+n);
	for(int i=1; i<n; i++){
		if(a[i] < a[i-1]){
			int d = a[i-1] - a[i];
			auto x = s.lower_bound(d);
			ans[(*x)-1] = i +1;
			s.erase(x);
		}
	}
	
	for(int i=0; i<n; i++){
		cout << (ans[i] == 0 ? 1 : ans[i]) << " \n"[i == n-1];
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
