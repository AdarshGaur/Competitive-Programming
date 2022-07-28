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
	int n, q;
	cin >> n >> q;
	
	int val[n+1], pos[n+1];
	for(int i=1; i<=n; i++){
		val[i] = i, pos[i] = i;
	}
	
	for(int i=0; i<q; i++){
		int x;
		cin >> x;
		
		int p1 = pos[x], p2 = pos[x];
		if(p1 == n) p2--;
		else p2++;
		
		int v1 = val[p1], v2 = val[p2];
		swap(val[p1], val[p2]);
		swap(pos[v1], pos[v2]);
	}
	
	for(int i=1; i<=n; i++){
		cout << val[i] << " \n"[i == n];
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
