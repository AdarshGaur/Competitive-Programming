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
	
	map<int,int> mp;
	int p[n];
	
	for(int i=0; i<n; i++){
		cin >> p[i];
		mp[p[i]] = i;
	}
	
	int cnt[n] = {};
	for(int i=0; i<n; i++){
		int x = mp[i];
		int shift = (x - i +n)%n;
		cnt[shift]++;
	}
	
	int ans = 0;
	for(int i=0; i<n; i++){
		int n1 =(i+1)%n, n2 = (i+2)%n;
		ans = max(ans, cnt[i] + cnt[n1] + cnt[n2]);
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
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
