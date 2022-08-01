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
	
	vector<int> c(m);
	vector<int> sum(n, 0);
	map<int,int> mp;
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> c[j];
			sum[i] += c[j]*j;
		}
		mp[sum[i]]++;
	}
	
	for(int i=0; i<n; i++){
		if(mp[sum[i]] == 1){
			cout << i+1 << " " << sum[i] - sum[ (i+1)%n ] << endl;
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
