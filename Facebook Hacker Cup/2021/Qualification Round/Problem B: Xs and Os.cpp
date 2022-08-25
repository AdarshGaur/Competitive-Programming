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
	int n;
	cin >> n;
	string c[n];
	for(auto& i: c)
		cin >> i;
	
	bool check[n][n] = {false};
	int mn = INT_MAX, cnt = 0;
	for(int i=0; i<n; i++){
		int x = 0, p = -1;
		for(auto j=0; j<n; j++){
			if(c[i][j] == 'X') continue;
			if(c[i][j] == 'O'){
				x = INT_MAX;
				break;
			}
			x++, p = j;
		}
		if(x == INT_MAX) continue;
		if(mn > x){
			mn = x, cnt = 0;
		}
		if(mn == x)
			cnt++;
		
		if(x == 1)
			check[i][p] = true;
	}
	
	for(int j=0; j<n; j++){
		int x = 0, p = -1;
		for(int i=0; i<n; i++){
			if(c[i][j] == 'X') continue;
			if(c[i][j] == 'O'){
				x = INT_MAX;
				break;
			}
			x++, p = i;
		}
		if(x == 1 and check[p][j]) continue;
		if(x == INT_MAX) continue;
		if(mn > x)
			mn = x, cnt = 0;
		if(mn == x) cnt++;
	}
	
	if(mn == INT_MAX){
		cout << "Impossible" << endl;
	}else{
		cout << mn << " " << cnt << endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
