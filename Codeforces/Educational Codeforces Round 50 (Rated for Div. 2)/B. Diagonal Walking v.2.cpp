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
	int n, m, k;
	cin >> n >> m >> k;
	int mn = min(n, m), mx = max(n, m);
	int more = mx - mn;
	if(mn + more > k){
		cout << -1 << endl;
		return;
	}
	int ans = mn;
	k -= mn;
	if( more%2 == 1 and k%2 == 1){
		k--, more--;
	}else if(more%2 == 1){
		more--;
		k -= 2;
		ans++;
	}else if(k&1){
		k--;
		ans--;
	}
	ans += k;
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
