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


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	
	int n, m;
	cin >> n >> m;
	
	map<pii,int> mp;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		mp[{a,b}]++;
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++){
		
		int x = 1;
		
		//odds
		for(int j=i+1, k=i-1; j<=n and k>=1; j++, k--){
			if(!mp.count({k, j})) break;
			x += 2;
			// mp.erase({k, j});
		}
		ans = max(ans, x);
		
		//evens
		x = 0;
		for(int j=i, k=i-1; j<=n and k>=1; j++, k--){
			if(!mp.count({k, j})) break;
			x += 2;
			// mp.erase({k, j});
		}
		ans = max(ans, x);
		
	}
	
	cout << ans << endl;
	
	return 0;
}
