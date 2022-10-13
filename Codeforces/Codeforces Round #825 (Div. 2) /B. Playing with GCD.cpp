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

int lcm(int a, int b){
	return (a * b)/__gcd(a,b);
}


void solve(){
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	string ans = "YES";
	int last = -1;
	for(int i=1; i<n; i++){
		int x = lcm(a[i], a[i-1]);
		if(last == -1){
			last = x;
			continue;
		}
		if(__gcd(last, x) != a[i-1]){
			ans = "NO";
			break;
		}
		last = x;
	}
	cout << ans << endl;
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
