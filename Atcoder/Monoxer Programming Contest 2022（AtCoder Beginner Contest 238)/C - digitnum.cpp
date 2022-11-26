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
int const mod = 998244353;


int sumUpto(int a){
	int x = a, y = a+1;
	if(x%2 == 0){
		x /= 2;
	}else{
		y /= 2;
	}
	return ((x%mod) * (y%mod))%mod;
}

void solve(){
	int n;
	cin >> n;
	
	int ans = 0, x = 10, p = 9;
	while(x <= n){
		ans = (ans + sumUpto(p))%mod;
		x *= 10;
		p *= 10;
	}
	
	x /= 10;
	x--;
	int last = n - x;
	ans = (ans + sumUpto(last)) %mod;
	cout << ans << endl;
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
