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
	int n = 2;
	int a[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	
	bool pos = false;
	for(int i=0; i<4; i++){
		swap(a[0][0], a[0][1]);
		swap(a[0][0], a[1][0]);
		swap(a[1][0], a[1][1]);
		if(a[0][0] < a[0][1] and a[1][0] < a[1][1] and a[0][0] < a[1][0] and a[0][1] < a[1][1]){
			pos = true;
		}
	}
	cout << (pos ? "YES" : "NO" ) << endl;
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
