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
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n+1, 0);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	
	int sum = 0;
	for(int i=1; i<=n; i++){
		int l = a[i-1] - a[i];
		if(i*l <= k){ // case 1 : can take all the previous ones (k is enough)
			sum += a[i-1] * i * l - i * (l*(l-1))/2;
			k -= i * l;
			debug(i, k, sum);
		}else{ // case 2 : can't take them all ( k is less)
			int r = k/i; // lines
			int s = k%i; // same a[i-1]s
			sum += a[i-1] * i * r - i * (r*(r-1))/2;
			sum += (a[i-1] - r) * s;
			debug(i, k, sum);
			break;
		}
	}
	cout << sum << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
