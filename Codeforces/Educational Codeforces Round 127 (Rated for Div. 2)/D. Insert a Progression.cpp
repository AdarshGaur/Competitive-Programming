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
	int n, x;
	cin >> n >> x;
	
	int a[n];
	int mn = INF, mx = 0, ans = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if(i > 0){
			ans += abs(a[i] - a[i-1]);
		}
	}
	
	int l = min<int>(mn-1, x), r = max<int>(mx+1, 1);
	auto total = INF;
	
	// {left, mid, right}
	vector<int> ls = {a[0] - 1, 2 * (l-1) + 2 * (mn-l), a[n-1] - 1};
	if(l < 1){
		ls[0] = ls[1] = ls[2] = 0;
	}
	
	vector<int> rs = {x - a[0], 2 * (x-r) + 2*(r-mx), x - a[n-1]};
	if(r > x){
		rs[0] = rs[1] = rs[2] = 0;
	}
	
	if(r < l){
		for(int i=0; i<3; i++){
			total = min({total, ls[i], rs[i]});
		}
		cout << ans + total << endl;
		return;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i == j and i != 1) continue;
			total = min(total, max<int>(ls[i] + rs[j], 0));
		}
	}
	
	cout << ans + total << endl;
	
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
