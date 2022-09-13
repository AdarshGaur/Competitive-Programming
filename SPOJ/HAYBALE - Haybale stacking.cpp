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
	int n, k;
	cin >> n >> k;
	
	int a[n];
	memset(a, 0, sizeof(a));
	for(int i=0; i<k; i++){
		int l, r;
		cin >> l >> r;
		l--, r--;
		a[l]++;
		if(r+1<n) a[r+1]--;
	}
	for(int i=1; i<n; i++){
		a[i] += a[i-1];
	}
	sort(a, a+n);
	cout << a[n/2] << endl;
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
