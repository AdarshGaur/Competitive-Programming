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
	
	vector<int> ans;
	int a = 0, b = 0;
	for(int i=1; i<n-1; i++){
		if(i &1){
			a ^= i;
		}else{
			b ^= i;
		}
		ans.push_back(i);
	}
	
	if(a == b){
		a ^= ans.back();
		ans.back() = 0;
	}

	a ^= 0xfffffff;
	b ^= 0xfffffff;
	ans.push_back(a);
	ans.push_back(b);
	
	for(int i=0; i<n; i++){
		cout << ans[i] << " \n"[i == n-1];
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
