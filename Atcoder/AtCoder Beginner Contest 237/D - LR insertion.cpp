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
	string s;
	cin >> n >> s;
	
	deque<int> dq;
	dq.push_back(n);
	for(int i=n-1; i>=0; i--){
		if(s[i] == 'L'){
			dq.push_back(i);
		}else{
			dq.push_front(i);
		}
	}
	
	cout << dq.front();
	dq.pop_front();
	while(!dq.empty()){
		cout << " " << dq.front();
		dq.pop_front();
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
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
