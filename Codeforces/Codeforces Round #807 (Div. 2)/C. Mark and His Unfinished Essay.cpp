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
	int n, c, q;
	string s;
	cin >> n >> c >> q >> s;
	
	int l[c], r[c];
	set<pii> ls;
	int xpos = n;
	for(int i=0; i<c; i++){
		cin >> l[i] >> r[i];
		ls.insert({xpos, l[i]-1});
		xpos += r[i] - l[i] +1;
	}
	
	while(q--){
		int k;
		cin >> k;
		k--;
		while(k>=n){
			auto it = ls.lower_bound({k,0});
			if(it == ls.end() or (it!=ls.end() and (*it).first != k))
				it--;
			auto [lpos, lr] = *it;
			k = k - lpos + lr;
		}
		cout << s[k] << endl;
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
