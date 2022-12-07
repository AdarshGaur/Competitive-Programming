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
	string s;
	int q;
	cin >> s >> q;
	
	auto successor = [&](char c, int jumps){
		// first change the base to 'A' to make it easier to find the
		// periodic successor of the character
		return char('A' + (c-'A' + jumps) % 3);
	};
	
	auto func = [&](auto self, int t, int k){
		if(t == 0) return s[k];
		if(k == 0) return successor(s[0], t);
		return successor(self(self, t-1, k/2), k%2 +1); // make it jump 2 times (it the same char) if we want to find the 2nd char of successor
	};
	
	while(q--){
		int t, k;
		cin >> t >> k;
		cout << func(func, t, k-1) << endl;
	}
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
