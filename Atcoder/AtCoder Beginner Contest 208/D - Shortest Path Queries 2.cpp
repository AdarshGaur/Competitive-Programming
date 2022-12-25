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
	// floyd-Warshall
	int n, m;
	cin >> n >> m;
	
	int d[n+1][n+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	
	int ans = 0;
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				if(d[i][j] < INF)
					ans += d[i][j];
			}
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
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
