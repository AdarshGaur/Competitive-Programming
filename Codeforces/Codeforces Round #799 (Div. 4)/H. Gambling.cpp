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
	for(int &i: a)
		cin >> i;
	map<int, pii> mp; // < x[i], {last good i, count of x[i] from that i } >
	int l = 0, r = -1, x = -1, ans = -1;
	for(int i=0; i<n; i++){
		int money = 1;
		if(mp.count(a[i])){
			int distance = i - mp[a[i]].first;
			int same = mp[a[i]].second;
			int dif = distance - same;
			if(dif >= same){
				mp[a[i]] = {i, 1};
			}else{
				mp[a[i]].second++;
				money = same - dif +1;
			}
		}else{
			mp[a[i]] = {i, 1};
		}
		int last = mp[a[i]].first;
		if(money > ans){
			x = a[i];
			l = last +1;
			r = i+1;
			ans = money;
		}
	}
	cout << x << " " << l << " " << r << endl;
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
