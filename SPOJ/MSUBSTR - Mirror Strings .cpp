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
	
	int n = s.size(), mx = 0, cnt = 0;
	vector<int> d1(n, 0), d2(n, 0);
	for(int i=0, l=0, r=-1; i<n; i++){
		int k = (i > r) ? 1 : min(d1[l + (r-i)], r-i);
		while(i+k<n and i-k>=0 and s[i+k] == s[i-k])
			k++;
		d1[i] = k--;
		if(i +k > r){
			l = i - k;
			r = i + k;
		}
		mx = max(mx, d1[i]*2 -1);
	}
	for(int i=0, l=0, r=-1; i<n; i++){
		int k = (i > r ? 0 : min(d2[l + (r-i+1)], r-i+1)) +1;
		while(i+k-1 < n and i-k >=0 and s[i+k-1] == s[i-k])
			k++;
		d2[i] = --k;
		if(i + k-1 > r){
			l = i - k;
			r = i + k -1;
		}
		mx = max(mx, d2[i]*2);
	}
	
	for(int i=0; i<n; i++){
		if(d2[i]*2 == mx) cnt++;
		if(d1[i]*2 -1 == mx) cnt++;
	}
	cout << mx << " " << cnt << endl;
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
