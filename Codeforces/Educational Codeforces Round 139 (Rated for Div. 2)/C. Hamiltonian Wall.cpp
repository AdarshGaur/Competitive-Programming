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
	int m;
	cin >> m;
	
	string s[2];
	cin >> s[0] >> s[1];
	
	int total = 0;
	for(int j=0; j<m; j++){
		total += s[0][j] == 'B';
		total += s[1][j] == 'B';
	}
	
	auto pos = [&](int x){
		int cnt = 0;
		for(int j=0; j<m; j++){
			if(s[x][j] != 'B') return false;
			cnt++;
			if(x == 1 and s[0][j] == 'B'){
				cnt++;
				x = 0;
			}else if(x == 0 and s[1][j] == 'B'){
				cnt++;
				x = 1;
			}
		}
		return cnt == total;
	};
	
	if(pos(0) or pos(1)){
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
