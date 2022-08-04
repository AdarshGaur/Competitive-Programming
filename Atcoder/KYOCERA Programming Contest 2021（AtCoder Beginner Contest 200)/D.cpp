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

void output(vector<int>& v){
	cout << v.size();
	for(int &i :v)
		cout << " " << i;
	cout << endl;
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i: a)
		cin >> i;
	
	vector<vector<int>> seq(201);
	int mn = min<int>(n, 8);
	
	for(int mask=0; mask<(1<<mn); mask++){
		vector<int> b;
		int sum = 0;
		for(int i=0; i<mn; i++){
			if(mask & (1<<i)){
				b.push_back(i+1);
				sum = (sum + a[i] +200) %200;
			}
		}
		
		if(!seq[sum].empty()){
			cout << "Yes" << endl;
			output(seq[sum]);
			output(b);
			return;
		}
		seq[sum] = b;
	}
	
	cout << "NO" << endl;
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
