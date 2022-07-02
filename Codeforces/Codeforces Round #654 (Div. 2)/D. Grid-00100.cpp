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
	int n, k, f{}, d{};
	cin >> n >> k;
	int mat[n][n];
	memset(mat, 0, sizeof(mat));
	while(k > 0){
		for(int i=0; i<n; i++){
			if(k == 0){
				f = 2;
				break;
			}
			int j = (i+d)%n;
			mat[j][i] = 1;
			k--;
		}
		d++;
	}
	cout << f << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << mat[i][j];
		}
		cout << endl;
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
