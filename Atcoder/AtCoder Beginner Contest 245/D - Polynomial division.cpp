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
	int n, m;
	cin >> n >> m;
	
	int A[n+1];
	for(int i=0; i<=n; i++){
		cin >> A[i];
	}
	
	int C[n+m+1];
	for(int i=0; i<=n+m; i++){
		cin >> C[i];
	}
	
	int B[m+1] = {};
	for(int i=m; i>=0; i--){
		B[i] = C[i+n]/A[n];
		for(int j=0; j<n; j++){
			C[i+j] -= B[i] * A[j];
		}
	}
	
	for(int i=0; i<=m; i++){
		cout << B[i] << " \n"[i == m];
	}
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
