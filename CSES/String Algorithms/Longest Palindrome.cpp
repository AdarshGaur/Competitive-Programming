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


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	
	string s;
	cin >> s;
	
	int n = s.size();
	int d1[n]={}, d2[n]={};
	
	// odd ones
	int l = 0, r = -1, mx = 0, start = 0;
	for(int i=0; i<n; i++){
		int k = (i > r) ? 1 : min(d1[l + (r-i)], r-i);
		while( i+k <n and i-k >=0 and s[i+k] == s[i-k])
			k++;
		d1[i] = k--;
		if(i + k > r)
			l = i-k, r = i+k;
		
		if(mx < d1[i]*2 -1){
			mx = d1[i]*2 -1;
			start = i - (d1[i] -1);
		}
	}
	
	l = 0, r = -1;
	for(int i=0; i<n; i++){
		int k = (i > r) ? 1 : min(d2[l + (r-i) +1] , r-i +1) +1;
		while( i+k-1 <n and i+k >=0 and s[i+k-1] == s[i-k])
			k++;
		d2[i] = --k;
		if(i + k -1 > r)
			l = i -k, r = i+k -1;
		
		if(mx < d2[i]*2){
			mx = d2[i] *2;
			start = i - d2[i];
		}
	}
	
	cout << s.substr(start, mx) << endl;
	
	return 0;
}
