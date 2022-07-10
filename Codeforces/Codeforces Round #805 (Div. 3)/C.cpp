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
	int n, k;
	cin >> n >> k;
	map<int,int> left, right;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		if(!left.count(x))
			left[x] = i;
		right[x] = i;
	}
	while(k--){
		int a, b;
		cin >> a >> b;
		bool pos = false;
		if(left.count(a) and right.count(b) and left[a] <= right[b])
			pos = true;
		cout << (pos ? "YES" : "NO") << endl;
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
