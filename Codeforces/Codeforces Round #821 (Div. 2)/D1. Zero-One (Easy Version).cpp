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
	int n, x, y;
	cin >> n >> x >> y;
	
	if(x > 2 * y)
		x = 2 * y;

	string a, b;
	cin >> a >> b;
	
	vector<int> cnt;
	for(int i=0; i<n; i++){
		if(a[i] != b[i]){
			cnt.push_back(i);
		}
	}
	
	if((int)cnt.size() &1){
		cout << -1 << endl;
	}else if((int)cnt.size() == 2){
		cout << (cnt.front() == cnt.back()-1 ? x : y) << endl;
	}else{
		cout << y * (cnt.size() / 2) << endl;
	}
	
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
