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
	
	int a[2][m];
	for(int i=0; i<2; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			a[i][j]++;
		}
	}
	
	int sufUp[m] = {}, sufDown[m] = {};
	int total = 2;
	a[0][0] = 0;
	sufUp[m-1] = max(a[0][m-1] +1, a[1][m-1]);
	sufDown[m-1] = max(a[0][m-1], a[1][m-1] +1);
	
	for(int i=m-2; i>=0; i--, total += 2){
		sufUp[i] = max({a[0][i] +total+1, a[1][i], sufUp[i+1]+1});
		sufDown[i] = max({a[1][i] +total+1, a[0][i], sufDown[i+1]+1});
	}
	
	int curTime = -1, ans = INF;
	for(int i=0; i<m; i++, total -= 2){
		if(i&1){ // suffix from downside
			int cur = max(sufDown[i], curTime +total);
			ans = min(ans, cur);
			
			// tetris movement
			curTime = max({curTime+2, a[0][i], a[1][i]+1});
			
		}else{ // suffix from upside
			int cur = max(sufUp[i], curTime +total);
			ans = min(ans, cur);
			
			//tetris movement
			curTime = max({curTime+2, a[0][i] +1, a[1][i]});
		}
	}
	cout << ans << endl;
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
