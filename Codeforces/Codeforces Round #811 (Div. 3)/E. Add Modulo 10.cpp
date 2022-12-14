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
	bool spc = false;
	for(int &i: a){
		cin >> i;
		int r = i%10;
		if(r == 1 or r == 2 or r == 4 or r == 8){
			i = (i/10)*10 +8;
		}else if(r == 6 or r == 7 or r == 3 or r == 9){
			i = (i/10 +1)*10 +8;
		}else if(r == 5){
			i += 5;
			spc = true;
		}else{
			spc = true;
		}
	}
	
	if(spc){
		for(int i=0; i<n; i++){
			if(a[i] != a[0]){
				cout << "NO" << endl;
				return;
			}
		}
	}
	
	int start = a[0]/10;
	for(int i=0; i<n; i++){
		int x = a[i]/10;
		if( x%2 != start%2){
			cout << "NO" << endl;
			return ;
		}
	}
	cout << "YES" << endl;
			
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
