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
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int& i: a)
		cin >> i;
	for(int &i: b)
		cin >> i;
	
	for(int i=0, j=0; i<n; i++){
		while(b[j] < a[i]) j++;
		int x = b[j] - a[i];
		cout << x << " \n"[i == n-1];
	}
	
	vector<int> mx(1, b[n-1] - a[n-1]);
	
	for(int i=n-2, j=n-1; i>=0; i--){
		if(a[i+1] > b[i])
			j = i;
		mx.emplace_back(b[j] - a[i]);
	}
	
	for(int i=n-1; i>=0; i--){
		cout << mx[i] << " \n"[i == 0];
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
