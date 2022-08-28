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
	
	int n = (int)s.size();
	
	int outerl=0, outerr=n-1;
	while(outerl < outerr and s[outerl] == s[outerr]){
		outerl++, outerr--;
	}
	if(outerl >= outerr){
		cout << s << endl;
		return;
	}
	
	int d1[n], d2[n];
	for(int i=0, l=0, r=-1; i<n; i++){
		int k = (i > r ? 1 : min(d1[l + (r-i)], r-i));
		while(i+k<n and i-k>=0 and s[i+k] == s[i-k])
			k++;
		d1[i] = k--;
		if(i + k > r){
			l = i - k, r = i + k;
		}
	}
	for(int i=0, l=0, r=-1; i<n; i++){
		int k = (i > r ? 0 : min(d2[l + (r-i+1)], r-i+1))+1;
		while(i+k-1<n and i-k>=0 and s[i+k-1] == s[i-k])
			k++;
		d2[i] = --k;
		if(i + k - 1 > r){
			l = i - k, r = i + k -1;
		}
	}
	
	int mx = 0, start = -1;
	for(int i=outerl; i<=outerr; i++){
		
		// odd lengths
		int l = i - d1[i] +1, r = i + d1[i]-1;
		if(l < outerl){
			int x = outerl - l;
			r -= x;
			l += x;
		}
		if(r > outerr){
			int x = r - outerr;
			l += x;
			r -= x;
		}
		if( l <= r and (l == outerl or r == outerr) and mx < r-l+1){
			mx = r - l +1;
			start = l;
		}
		
		// even lengths
		l = i - d2[i], r = i + d2[i] -1;
		if(l < outerl){
			int x = outerl - l;
			r -= x;
			l += x;
		}
		if(r > outerr){
			int x = r - outerr;
			r -= x;
			l += x;
		}
		if( l <= r and (l == outerl or r == outerr) and mx < r - l +1){
			mx = r - l +1;
			start = l;
		}
	}
	
	
	string ans = s.substr(0, outerl);
	auto temp = ans;
	reverse(temp.begin(), temp.end());
	if(start != -1)
		ans += s.substr(start, mx) + temp;
	
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
