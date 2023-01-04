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
	int q;
	cin >> q;
	deque<int> dq;
	multiset<int> s;
	for(int i=0; i<q; i++){
		int c, x;
		cin >> c;
		if(c == 1){
			cin >> x;
			dq.push_back(x);
		}else if(c == 2){
			if(!s.empty()){
				cout << *s.begin() << endl;
				s.erase(s.begin());
			}else{
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}else{
			while(!dq.empty()){
				s.insert(dq.front());
				dq.pop_front();
			}
		}
	}
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
