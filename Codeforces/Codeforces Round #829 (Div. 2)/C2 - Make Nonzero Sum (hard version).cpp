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
	int n, sum = 0;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum += a[i];
	}
	
	if(sum % 2 != 0){
		cout << -1 << endl;
		return;
	}
	
	vector<pii> segs;
	for(int i=0; i<n; i++){
		if(a[i] == 0){
			segs.push_back({i, i});
			continue;
		}
		sum = a[i];
		int j = i+1, sign = -1;
		while(j < n and a[j] == 0){
			j++;
			sign *= -1;
		}
		if(a[i] != sign*a[j]){
			segs.push_back({i, j});
		}else{
			segs.push_back({i,i});
			segs.push_back({i+1, j});
		}
		i = j;
	}
	
	cout << segs.size() << endl;
	for(auto [u, v]: segs)
		cout << u+1 << " " << v+1 << endl;
	
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
