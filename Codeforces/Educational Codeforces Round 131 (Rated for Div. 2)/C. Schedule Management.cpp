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
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, m;
	cin >> n >> m;
	int a[n]{};
	for(int i=0; i<m; i++){
		int w; cin >> w;
		a[w-1]++;
	}
	int l = 0, r = m;
	while(l < r){
		int mid = l + (r - l)/2;
		int tasks{}, extra{};
		for(int i=0; i<n; i++){
			if(a[i] >= mid){
				tasks += a[i] - mid;
			}else{
				extra += (mid - a[i])/2;
			}
		}
		if(tasks > extra){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	cout << l << endl;
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
