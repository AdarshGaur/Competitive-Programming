// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "debug.h"
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

#define int int64_t
// #define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;

int ask(string& s){
	cout << "? " << s << endl;
	int val;
	cin >> val;
	return val;
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	string s(m, '0');
	pii a[m];
	for(int i=0; i<m; i++){
		s[i] = '1';
		a[i] = {ask(s), i};
		s[i] = '0';
	}
	
	sort(a, a+m);
	int ans = 0, last = 0;
	for(auto &[v, i]: a){
		s[i] = '1';
		int x = ask(s);
		if(last + v == x){
			ans += v;
		}
		last = x;
	}
	
	cout << "! " << ans << endl;
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
