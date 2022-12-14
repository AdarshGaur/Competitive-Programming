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
	string t;
	int n, m;
	cin >> t >> n;
	
	m = t.size();
	string s[n];
	map<string, int> mp;
	for(int i=0; i<n; i++){
		cin >> s[i];
		mp[s[i]] = i;
	}
	
	vector<int> ans(m+1, INT_MAX), sused(m+1, -1), back(m+1, -1);
	ans[0] = 0;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=10 and i-j>=0; j++){
			string red = t.substr(i-j, j);
			if(mp.count(red)){ // steps = ans[i-j] +1
				for(int k = 1; k <= j; k++){
					if(ans[i - j + k] > ans[i-j] +1){
						ans[i-j +k] = ans[i-j] +1;
						sused[i-j+k] = mp[red];
						back[i-j+k] = i - j;
					}
				}
			}
		}
	}
	
	if(ans[m] == INT_MAX){
		cout << -1 << endl;
		return;
	}
	
	cout << ans[m] << endl;
	int p = m;
	while(p > 0){
		int indx = sused[p], start = back[p] +1;
		cout << indx+1 << " " << start << endl;
		p = start -1;
	}
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
