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
	
	if(n == 1){
		cout << 1 << endl;
		return ;
	}
	
	
	int cnt = 1, ans = 0, last = a[1] - a[0];
	for(int i=1; i < n; i++){
		if(last > 0){
			if(a[i] - a[i-1] > 0){
				cnt++;
			}else{
				ans += (cnt*(cnt-1))/2;
				cnt = 2;
				last = -1;
			}
		}else if(last < 0){
			cnt++;
			if(a[i] - a[i-1] > 0){
				last = 1;
			}
		}
	}
	
	ans += (cnt * (cnt-1))/2;
	
	cout << ans +n << endl;
	
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
