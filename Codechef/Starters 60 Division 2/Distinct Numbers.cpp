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
	int n, k;
	cin >> n >> k;
	
	set<int> s, t;
	for(int i=1; i<= 2*n; i++) t.insert(i);
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		s.insert(x);
		t.erase(t.lower_bound(x));
	}
	
	while((int)t.size() > k){
		int last = *t.rbegin();
		t.erase(last);
	}
	
	auto tt = t;
	
	int mx2 = 0;
	if(!s.count(2*n)){
		int last = *tt.rbegin();
		tt.erase(last);
		for(auto i: tt)
			mx2 += 2*n - i;
	}
	
	int mx1 = 0;
	for(auto i: t){
		s.insert(i);
		mx1 += (*s.rbegin()) - i;
	}
	
	cout << max(mx1, mx2) << endl;
	
		
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
