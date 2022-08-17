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
	vector<int> a(n);
	for(int &i: a)
		cin >> i;
	
	int sum = 0;
	vector<int> save(n);
	for(int i=0; i<n; i++){
		save[i] = a[i] - (n-1 - i);
		sum += a[i];
	}
	sum -= (k * (k-1))/2;
	
	sort(save.rbegin(), save.rend());
	for(int i=0; i<k; i++)
		sum -= save[i];
	cout << sum << endl;
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