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
	int n, l ,r;
	cin >> n >> l >> r;
	
	vector<int> ans;
	for(int i=1; i<=n; i++){
		int x = r%i;
		if(r - x < l){
			cout << "NO" << endl;
			return;
		}
		ans.push_back(r - x);
	}
	cout << "YES" << endl;
	for(int i=0; i<n; i++)
		cout << ans[i] << " \n"[i == n-1];
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
