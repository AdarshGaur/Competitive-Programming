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
	string s;
	cin >> s;
	
	int col[m] = {}, cache[n*m] = {};
	int firstRow = 0, goodCol = 0;
	for(int i=0; i<n*m; i++){
		if(s[i] == '1'){
			if(col[i%m] == 0) goodCol++;
			col[i%m] = 1;
		}
		
		if(i >= m){
			firstRow -= (s[i - m] - '0');
		}
		firstRow += (s[i] - '0');
		
		if(i < m){
			cache[i] = firstRow != 0;
		}else{
			cache[i] = cache[i-m] + (firstRow != 0);
		}
		
		cout << cache[i] + goodCol << " \n"[i == n*m -1];
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
