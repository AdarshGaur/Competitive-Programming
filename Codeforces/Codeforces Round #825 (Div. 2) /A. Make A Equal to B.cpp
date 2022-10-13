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
	int n;
	cin >> n;
	
	int x = 0, y = 0;
	int a[n], b[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		x += (a[i] == 0);
	}
	for(int i=0; i<n; i++){
		cin >> b[i];
		y += (b[i] == 0);
	}
	
	int cnt =0 ;
	for(int i=0; i<n; i++){
		if(a[i] != b[i]){
			cnt++;
			a[i] = b[i];
		}
	}
	
	cout << min(cnt, abs(y-x)+1) << endl;
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
