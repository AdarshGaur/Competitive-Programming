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
	int n;
	string s, t;
	cin >> n >> s >> t;
	if(s[0] != t[0] or t.back() != s.back()){
		cout << -1 << endl;
		return;
	}
	vector<int> ss, tt;
	for(int i=0; i<n-1; i++){
		if(s[i] != s[i+1]) ss.push_back(i);
		if(t[i] != t[i+1]) tt.push_back(i);
	}
	if(ss.size() != tt.size()){
		cout << -1 << endl;
		return;
	}
	int ans{};
	for(int i=0; i<(int)ss.size(); i++){
		ans += abs(ss[i] - tt[i]);
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
