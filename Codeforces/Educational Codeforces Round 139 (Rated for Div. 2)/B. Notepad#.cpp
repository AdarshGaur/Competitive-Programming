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
	int n;
	cin >> n >> s;
	map<string, bool> mp;
	
	bool pos = false;
	string t = s.substr(0,2);
	mp[t] = true;
	for(int i=2; i<n-1; i++){
		t[0] = s[i];
		t[1] = s[i+1];
		if(mp.count(t)){
			pos = true;
			break;
		}
		t[0] = s[i-1];
		t[1] = s[i];
		mp[t] = true;
	}
	cout << (pos ? "YES" : "NO" ) << endl;
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
