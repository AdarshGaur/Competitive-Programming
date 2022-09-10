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

int length(int x){
	int l = 0;
	while(x){
		l++;
		x /= 10;
	}
	return l;
}

void solve(){
	int n;
	cin >> n;
	
	multiset<int> a, b;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		a.insert(x);
	}
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(a.find(x) != a.end()){
			a.erase(a.find(x));
		}else{
			b.insert(x);
		}
	}
	
	
	int ans = 0;
	map<int,int> mpa, mpb;
	for(auto i: a){
		if(i >= 10){
			ans++;
			int x = length(i);
			mpa[x]++;
		}else{
			mpa[i]++;
		}
	}
	
	for(auto i: b){
		if(i < 10){
			mpb[i]++;
		}else{
			ans++;
			int x = length(i);
			mpb[x]++;
		}
	}
	
	for(int i=2; i<10; i++){
		ans += abs(mpb[i] - mpa[i]);
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
