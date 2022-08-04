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
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int &i: a)
		cin >> i;

	string res(n, '0');
	auto check = [&](int m){
		int iq = q;
		for(int i=0; i<m; i++){
			if(a[i] <= iq)
				res[i] = '1';
			else
				res[i] = '0';
		}
		for(int i=m; i<n; i++){
			res[i] = '1';
			if(iq == 0) return false;
			if(a[i] > iq){
				iq--;
			}
		}
		return true;
	};
	
	int lo = 0, hi = n-1, ans = n-1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(check(mid)){
			hi = mid -1;
			ans = mid;
		}else{
			lo = mid +1;
		}
	}
	
	check(ans);
	cout << res << endl;
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
