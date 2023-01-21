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
	int n, m;
	cin >> n >> m >> s;
	
	int mnx = 0, mxx = 0, mny = 0, mxy = 0, x = 0, y = 0;
	vector<int> ans = {1,1};
	for(auto &c: s){
		if(c == 'L') x--;
		else if(c == 'R') x++;
		else if(c == 'U') y--;
		else y++;
		
		mnx = min(mnx, x);
		mny = min(mny, y);
		mxx = max(mxx, x);
		mxy = max(mxy, y);
		
		if((mxx - mnx < m) and (mxy - mny < n)){
			ans = {1 - mny, 1 - mnx};
		}
	}
	cout << ans[0] << " " << ans[1] << endl;
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
