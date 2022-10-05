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
	
	int a[n];
	for(int& i: a)
		cin >> i;
	
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	
	cout << n-1 << endl;
	cout << 1 << " " << n << endl;
	
	if((a[0] + a[n-1]) % 2 == 0) a[0] = a[n-1];
	else a[n-1] = a[0];
	
	for(int i=1; i<n-1; i++){
		if((a[i] + a[0]) % 2 == 0){
			cout << i+1 << " " << n << endl;
		}else{
			cout << 1 << " " << i + 1 << endl;
		}
	}
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
