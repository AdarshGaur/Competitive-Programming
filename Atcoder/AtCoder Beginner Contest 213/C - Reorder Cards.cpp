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
typedef tuple<int,int,int> tp;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	int h, w, n;
	cin >> h >> w >> n;
	
	tp p[n];
	int j = 0, last = INF;
	for(auto &[a, b, c]: p){
		cin >> a >> b;
		c = j++;
	}
	
	sort(p, p+n);
	j = 0;
	for(int i=0; i<n; i++){
		auto &[a, b, c] = p[i];
		if(last != a) j++;
		last = a;
		a = j;
	}
	
	sort(p, p+n, [&](tp& a, tp& b){
		return get<1>(a) < get<1>(b);
	});
	
	j = 0, last = INF;
	for(int i=0; i<n; i++){
		auto &[a, b, c] = p[i];
		if(last != b) j++;
		last = b;
		b = j;
	}
	
	sort(p, p+n, [&](tp& a, tp& b){
		return get<2>(a) < get<2>(b);
	});
	
	for(auto &[a, b, c]: p)
		cout << a << " " << b << endl;
		
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
