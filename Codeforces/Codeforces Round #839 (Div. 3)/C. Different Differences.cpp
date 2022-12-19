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
	int k, n;
	cin >> k >> n;
	
	vector<int> ans;
	int req = k-1;
	for(int i=1, d=0; i<=n and (int)ans.size() < k; i+=d, req--){
		if(n - i >= req) ans.push_back(i);
		else break;
		d++;
	}
	
	while((int)ans.size() < k){
		ans.push_back(ans.back() +1);
	}
	
	for(int i_=0; i_<k; i_++){
		cout << ans[i_] << " \n"[i_ == k-1];
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
