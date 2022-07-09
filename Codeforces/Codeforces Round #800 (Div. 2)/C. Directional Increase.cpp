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
	int n, sum{};
	cin >> n;
	int a[n];
	for(int &i: a){
		cin >> i;
		sum += i;
	}
	string ans = "YES";
	if(sum != 0) ans = "NO";
	for(int i=0, flag = 0; i<n-1; i++){
		if(a[i] <= 0){
			if(a[i] < 0){
				ans = "NO";
				break;
			}
			flag = 1;
			continue;
		}
		if(flag){
			ans = "NO";
			break;
		}
		a[i+1] += a[i];
	}
	if(a[n-1] != 0) ans = "NO";
	cout << ans << endl;
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
