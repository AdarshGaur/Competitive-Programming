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
	string w;
	int p, n;
	cin >> w >> p;
	n = w.size();
	int pp = 0;
	for(auto i: w){
		pp += ( i - 'a')+1;
	}
	string s(w.begin(), w.end());
	sort(s.begin(), s.end());
	multiset<char> st;
	for(int i=n-1; i>=0; i--){
		if(pp <= p) break;
		int v = (s[i] - 'a') +1;
		st.insert(s[i]);
		pp -= v;
	}
	string ans = "";
	for(int i=0; i<n; i++){
		if(st.count(w[i])){
			auto it = st.lower_bound(w[i]);
			st.erase(it);
		}else{
			ans += w[i];
		}
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
