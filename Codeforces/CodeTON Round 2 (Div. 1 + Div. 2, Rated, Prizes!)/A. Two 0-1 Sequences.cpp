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
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	
	bool pos = true;
	if(n == m){
		pos = (a == b);
	}else if(n < m){
		pos = false;
	}else{
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		if(b.substr(0, m-1) != a.substr(0, m-1)){
			pos = false;
		}else{
			pos = false;
			for(int i=m-1; i<n; i++){
				if(a[i] == b[m-1]){
					pos = true;
				}
			}
		}
	}
	cout << (pos ? "YES" : "NO") << endl;
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
