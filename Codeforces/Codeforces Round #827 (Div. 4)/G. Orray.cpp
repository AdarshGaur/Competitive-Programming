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
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	int OR = 0;
	vector<int> ans;
	
	for(int j=30; j>=0; j--){
		int mx = -1, x = -1;
		for(int i=0; i<n; i++){
			if(a[i] < 0) continue;
			int r = (a[i]^OR)&a[i];
			if( r > x){
				x = r;
				mx = i;
			}
		}
		if(x < 0) continue;
		ans.push_back(a[mx]);
		OR |= a[mx];
		a[mx] = -1;
	}
	
	for(int i=0; i<n; i++){
		if(a[i] != -1){
			ans.push_back(a[i]);
		}
	}
	
	for(int i=0; i<n; i++)
		cout << ans[i] << " \n"[i == n-1];
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
