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
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n;
	cin >> n;
	vector<int> a(n+2, 0);
	set<int> good, ans;
	for(int i=0; i<n; i++){
		int l, r;
		cin >> l >> r;
		a[l]++, a[r+1]--;
		if(l <= i+1 and r >= i+1)
			good.insert(i+1);
	}
	int sum = 0;
	for(int i=1; i<=n; i++){
		sum += a[i];
		a[i] = sum;
	}
	for(int i=1; i<=n; i++){
		if( a[i] == n-1 ){
			auto it = good.lower_bound(i);
			if( it != good.end() and *it == i) continue;
			ans.insert(i);
		}
	}
	cout << ans.size() << endl;
	for(auto i: ans){
		cout << i << endl;
	}
}

signed main()
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
