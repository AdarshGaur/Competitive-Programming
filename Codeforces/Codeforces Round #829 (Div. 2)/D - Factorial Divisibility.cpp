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
	
	map<int,int> mp;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		mp[a]++;
	}
	
	map<int,int> cnt;
	for(auto &[u, v]: mp){
		if(u == x) continue;
		int a = u +1, t = v;
		while(a <= x and t % a == 0){
			t /= a;
			a++;
		}
		if(a > x) continue;
		if(cnt.count(a)) cnt[a] += t;
		else cnt[a] = t;
		
		while(a <= x and cnt[a] % a == 0){
			if(!cnt.count(a+1)) cnt[a+1] = 0;
			cnt[a+1] += cnt[a] /a;
			cnt[a++] = 0;
		}
	}
	
	for(auto [a, t]: cnt){
		if(a <= x and  t != 0 ){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	
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
