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
	
	if(m < n or (n%2 == 0 and m%2 == 1)){
		cout << "NO" << endl;
		return ;
	}
	
	cout << "YES" << endl;
	while(n > 2){
		cout << "1 1 ";
		n -= 2;
		m -= 2;
	}
	if(n&1){
		cout << m << endl;
	}else{
		cout << m/2 << " " << m/2 << endl;
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
