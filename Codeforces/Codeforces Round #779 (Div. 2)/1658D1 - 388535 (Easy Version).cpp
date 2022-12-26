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
	int l, r;
	cin >> l >> r;
	
	int a[r+1];
	for(int i=0; i<=r; i++){
		cin >> a[i];
	}
	
	int bits1[18]{}, bits2[18]{};
	for(int j=0; j<18; j++){
		for(int i=0; i<=r; i++){
			if(a[i] & (1<<j)) bits1[j]++;
			if(i & (1<<j)) bits2[j]++;
		}
	}
	
	int ans = 0;
	for(int j=0; j<18; j++){
		if(bits1[j] != bits2[j]){
			ans |= (1<<j);
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
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
