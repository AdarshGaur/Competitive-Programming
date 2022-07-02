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
	int n, m;
	cin >> n;
	vector<int> a(n);
	for(int &i: a)
		cin >> i;
	a.push_back(1e10);
	cin >> m;
	vector<int> b(m);
	for(int &i: b)
		cin >> i;
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	pii ans = {0,INF};
	int apoints = 3 * n, bpoints = m * 3, d = 0, j= 0;
	for(int i=0; i<=n; i++){
		d = a[i]-1;
		if(i != 0) apoints--;
		while(j<m and b[j] <= d)
			bpoints--, j++;
		if(apoints - bpoints > ans.first - ans.second){
			ans = {apoints, bpoints};
		}
	}
	cout << ans.first << ":" << ans.second << endl;
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
