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
	
	priority_queue<int> a, b;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		a.push(x);
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		b.push(x);
	}
	
	auto f = [&](int x){
		return to_string(x).length();
	};
	
	int ans = 0;
	while(!a.empty()){
		int x = a.top();
		int y = b.top();
		
		if(x == y){
			a.pop();
			b.pop();
		}else if(x < y){
			ans++;
			b.pop();
			b.push(f(y));
		}else{
			ans++;
			a.pop();
			a.push(f(x));
		}
	}
	cout << ans << endl;
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
