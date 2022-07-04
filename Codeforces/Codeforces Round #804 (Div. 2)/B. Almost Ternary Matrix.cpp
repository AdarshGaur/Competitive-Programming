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
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, m;
	cin >> n >> m;
	int mat[n][m];
	int x = 0, y = 1;
	for(int i=0; i<n; i+=2){
		mat[i][0] = x;
		mat[i+1][0] = y;
		swap(x, y);
	}
	for(int i=0; i<n; i++){
		x = 0, y = 1;
		if(mat[i][0] == 1) swap(x, y);
		for(int j=0; j<m; j+=2){
			mat[i][j] = x;
			mat[i][j+1] = y;
			swap(x, y);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << mat[i][j] << " \n"[j == m-1];
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
