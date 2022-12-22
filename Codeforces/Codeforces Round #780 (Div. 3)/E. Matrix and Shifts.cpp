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
	int n, total = 0;
	cin >> n;
	
	string a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		total += count(a[i].begin(), a[i].end(), '1');
	}
	
	int ans = INF, ones = 0, zeros = 0;
	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++){
			int x = (i+j)%n, y = j;
			if(a[x][y] == '1'){
				ones += 1;
			}else{
				zeros += 1;
			}
		}
		ans = min(ans, total - ones + zeros);
		ones = zeros = 0;
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
