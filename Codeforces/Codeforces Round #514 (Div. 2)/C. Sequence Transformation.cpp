// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "../../Debug.h"
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
	int n, ans = 1;
	cin >> n;
	while(n){
		if(n == 3){
			cout << ans << " " << ans << " " << 3*ans;
			break;
		}else if(n <= 2){
			for(int i=0; i<n; i++){
				cout << ans << " ";
				ans *= 2;
			}
			break;
		}
		for(int i=0; i< n - n/2; i++){
			cout << ans << " ";
		}
		n /= 2;
		ans *= 2;
	}
	cout << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
