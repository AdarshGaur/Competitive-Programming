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
	int n, x, y;
	cin >> n >> x >> y;
	
	if(min(x,y) != 0 or max(x,y) == 0 or (n-1)%max(x,y) != 0){
		cout << -1 << endl;
		return ;
	}
	
	int moves = x + y;
	for(int i=1, j=2; i<n; i++){
		cout << j << " \n"[i == n-1];
		if(i % moves == 0)
			j = i+2;
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
