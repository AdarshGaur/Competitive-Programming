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
	
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	int common = 0, inc = 0, dec = 0;
	for(int i=0; i<n; i++){
		if(a[i] != i+1 and a[i] != n-i){
			common++;
			continue;
		}
		if(a[i] != i+1) inc++;
		if(a[i] != n-i) dec++;
	}
	
	string winner = "-";
	if(inc > dec){
		inc -= dec;
		if(inc <= common){
			winner = "Tie";
		}else{
			winner = "Second";
		}
	}else if(dec > inc){
		dec -= inc;
		if(dec < common){
			winner = "Tie";
		}else{
			winner = "First";
		}
	}else{
		if(common > 0){
			winner = "Tie";
		}else{
			winner = "First";
		}
	}
	
	cout << winner << endl;
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
