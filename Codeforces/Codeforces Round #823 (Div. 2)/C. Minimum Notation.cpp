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
	string s;
	cin >> s;
	
	int n = s.size();
	vector<int> buff(10, 0);
	
	int mn = 9;
	for(int i=n-1; i>=0; i--){
		if(s[i] - '0' <= mn){
			buff[s[i] - '0']++;
			mn = s[i] - '0';
		}else{
			buff[min((s[i] - '0') +1, 9)]++;
		}
	}
	
	for(int i=0; i<10; i++){
		cout << string(buff[i], '0'+i);
	}
	cout << endl;
	
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
