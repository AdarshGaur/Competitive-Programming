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
	int a[n];
	for(int &i: a)
		cin >> i;
	
	vector<vector<int>> seq(201);
	vector<int> b;
	int ans = -1;
	
	function<bool(int, int)> backtrack = [&](int cur, int sum){
		if(cur == n) return false;
		b.push_back(cur);
		sum = (sum + a[cur] +200) %200;
		if(!seq[sum].empty()){
			ans = sum;
			return true;
		}
		seq[sum] = b;
		if( backtrack(cur+1, sum) ) return true;
		b.pop_back();
		sum = (sum - a[cur] + 200) %200;
		if( backtrack(cur+1, sum)) return true;
		return false;
	};
	
	backtrack(0, 0);
	if(ans == -1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		n = b.size();
		cout << n << " ";
		for(int i=0; i<n; i++)
			cout << b[i]+1 << " \n"[i == n-1];
		n = seq[ans].size();
		cout << n << " ";
		for(int i=0; i<n; i++)
			cout << seq[ans][i]+1 << " \n"[i == n-1];
	}
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
