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
	
	int a[n], b[n];
	for(int &i: a)
		cin >> i;
	for(int &i: b)
		cin >> i;
	
	auto check = [&](int ans){
		map<int,int> mp;
		for(int &i: a)
			mp[i & ans]++;
		for(int &i: b)
			mp[~i & ans]--;
		
		bool pos = true;
		for(auto [mask, cnt]: mp)
			pos = (pos & (cnt == 0));
		return pos;
	};
	
	int ans = 0;
	for(int i=30; i>=0; i--){
		if(check(ans | (1<<i)))
			ans |= (1<<i);
	}
	cout << ans << endl;
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
