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
typedef tuple<int,int,int> item;

int const INF = 2e18;
int const mod = 1e9 +7;



void solve(){
	int n, m;
	cin >> n >> m;

	int a[m];
	for(int &i: a)
		cin >> i;
	sort(a, a+m);
	
	vector<int> segments(m);
	for(int i=0; i<m-1; i++){
		segments[i] = max<int>(0, a[i+1] - a[i] -1);
	}
	segments[m-1] = max<int>(0, a[0] +n - a[m-1] -1);
	sort(segments.begin(), segments.end());
	
	int ans = m, days{};
	for(int i=m-1; i>=0; i--){
		int infected = min(segments[i], days*2);
		days++;
		ans += infected;
		segments[i] -= infected;
		if(segments[i] > 1){
			ans++;
			days++;
		}
	}
	
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
