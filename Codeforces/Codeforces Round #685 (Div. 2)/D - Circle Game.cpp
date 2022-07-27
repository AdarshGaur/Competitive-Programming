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
	int d, k;
	cin >> d >> k;
	
	int x = 0;
	while( (x+k)*(x+k)*2 <= d*d){
		x += k;
	}
	
	if( x*x + (x+k)*(x+k) <= d*d){
		cout << "Ashish" << endl;
	}else{
		cout << "Utkarsh" << endl;
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
