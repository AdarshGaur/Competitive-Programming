// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#	include "debug.h"
#else
#	define debug(...) "Make Haste Slowly."
#endif

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	string s;
	cin >> s;
	
	set<int> st[26];
	for(int i=0; i<(int)s.size(); i++){
		st[s[i] - 'a'].insert(i+1);
	}
	
	int q; cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int pos;
			char c;
			cin >> pos >> c;
			
			int prev = s[pos-1] - 'a';
			st[prev].erase(st[prev].lower_bound(pos));
			st[c - 'a'].insert(pos);
			s[pos-1] = c;
			
		}else{
			int l, r, cnt{};
			cin >> l >> r;
			
			for(int i=0; i<26; i++){
				auto it = st[i].lower_bound(l);
				if(it != st[i].end() and (*it) <= r) cnt++;
			}
			
			cout << cnt << endl;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
