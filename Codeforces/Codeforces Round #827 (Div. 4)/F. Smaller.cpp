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
	
	map<char, int> mp1, mp2;
	for(auto c='a'; c<='z'; c++){
		mp1[c] = 0;
		mp2[c] = 0;
	}
	mp1['a'] = 1;
	mp2['a'] = 1;
	
	while(q--){
		int d, k;
		string x;
		cin >> d >> k >> x;
		for(auto &c: x){
			if(d == 1) mp1[c] += k;
			else mp2[c] += k;
		}
		
		string ans = "-";
		auto i = 'a', j = 'z';
		while(ans == "-"){
			while(i <= 'z' and mp1[i] == 0) i++;
			while(j >= 'a' and mp2[j] == 0) j--;
			
			// for non zero length of both the strings;
			if( i == j){
				if(mp1[i] == mp2[j]){
					i++, j--;
				}else if(mp1[i] > mp2[j]){
					ans = "NO";
				}else{
					i++;
				}
			}else{
				if(j < 'a'){
					ans = "NO";
				}else if(i > 'z'){
					ans = "YES";
				}else{
					ans = i < j ? "YES" : "NO";
				}
			}
		}
		cout << ans << endl;
	}
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
