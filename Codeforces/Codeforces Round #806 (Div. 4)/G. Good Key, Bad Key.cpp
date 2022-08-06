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
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int &i: a)
		cin >> i;
	
	vector<vector<int>> cache(n, vector<int>(32, -1));
	
	function<int(int,int)> dp = [&](int cur, int jumps){
		if(cur == n) return n-cur;
		if(jumps == 32) return jumps-32;
		if(cache[cur][jumps] != -1)
			return cache[cur][jumps];
		int x = (a[cur] >> jumps) - k + dp(cur+1, jumps);
		int y = (a[cur] >> (jumps+1)) + dp(cur+1, jumps+1);
		return cache[cur][jumps] = max<int>(x, y);
	};
	
	cout << dp(0, 0) << endl;
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
