// Author : @AdarshGaur

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
	int n, q;
	cin >> n >> q;
	
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	string ans(n, '0');
	int cur = 0;
	for(int i=n-1; i>=0; i--){
		if(a[i] <= cur){
			ans[i] = '1';
		}else if(cur < q){
			cur++;
			ans[i] = '1';
		}
	}
	
	cout << ans << endl;
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
