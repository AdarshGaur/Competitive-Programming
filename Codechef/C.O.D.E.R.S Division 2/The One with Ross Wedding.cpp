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
	int n, p, q;
	cin >> n >> p >> q;
	
	string s;
	cin >> s;
	
	int toggle = 1;
	int d = 0, x = 0, y = 0;
	for(int i=0; i<n; i++){
		if(s[i] == '1'){
			d++;
		}else{
			if(toggle) x += d;
			else y += d;
			toggle ^= 1;
			d = 1;
		}
	}
	
	if(toggle) x += d;
	else y += d;
	
	auto check = [&](int P, int X){
		if(abs(P) <= X and (abs(P)-X) % 2 == 0)
			return true;
		return false;
	};
	
	if((check(p, x) and check(q, y)) or (check(p, y) and check(q, x))){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
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
