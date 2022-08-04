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
	int open = n/2 - count(s.begin(), s.end(), '(');
	int last = -1, first = n+1;
	
	for(int i=0; i<n; i++){
		if(s[i] == '?'){
			if(open){
				open--;
				s[i] = '(';
				last = max(last, i);
			}else{
				s[i] = ')';
				first = min(first, i);
			}
		}
	}
	if(last == -1 or first == n+1){
		cout << "YES" << endl;
		return;
	}
	
	swap(s[last], s[first]);
	int bal = 0;
	for(int i=0; i<n; i++){
		if(s[i] == '(')
			bal++;
		else
			bal--;
		if(bal < 0)
			break;
	}
	cout << (bal == 0 ? "NO" : "YES" ) << endl;
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
