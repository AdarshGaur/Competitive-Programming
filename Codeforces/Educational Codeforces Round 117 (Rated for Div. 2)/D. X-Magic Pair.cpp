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
	int a, b, x;
	cin >> a >> b >> x;
	
	bool pos = (a == x or b == x);
	while(a > 0 and b > 0 and !pos){
		if(x > a and x > b) break;
		if(b > a){
			b %= a;
			pos = b == x;
			if(x > b){
				int r = x - b;
				if(r % a == 0){
					pos = true;
				}
			}
		}else{
			a %= b;
			pos = a == x;
			if(x > a){
				int r = x - a;
				if(r % b == 0){
					pos = true;
				}
			}
		}
	}
	cout << (pos ? "YES" : "NO") << endl;
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
