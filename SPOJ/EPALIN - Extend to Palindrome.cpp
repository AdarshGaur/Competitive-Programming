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
	string s;	
	while(getline(cin, s)){
		if(s.empty()) break;
		
		int n = s.size();
		vector<int> d1(n, 0), d2(n, 0);
		vector<bool> suffix(n+1, false);
		
		for(int i=0, l=0, r=-1; i<n; i++){
			int k = (i > r) ? 1 : min(d1[l + (r-i)], r-i);
			while(i+k<n and i-k>=0 and s[i+k] == s[i-k])
				k++;
			d1[i] = k--;
			if(i + k > r){
				l = i - k;
				r = i + k;
			}
			
			if(i + d1[i] == n)
				suffix[ i - d1[i] +1] = true;
		}
		for(int i=0, l=0, r=-1; i<n; i++){
			int k = (i>r ? 0 : min(d2[l + (r-i+1)], r-i+1)) +1;
			while(i+k-1 < n and i-k>=0 and s[i-k] == s[i+k-1])
				k++;
			d2[i] = --k;
			if(i + k -1 > r){
				l = i - k;
				r = i + k -1;
			}
			
			if(i + d2[i] == n)
				suffix[i - d2[i]] = true;
		}
		
		suffix[n] = true;
		string t;
		
		for(int i=0; i<=n; i++){
			if(suffix[i]){
				t = s.substr(0, i);
				break;
			}
		}
		
		reverse(t.begin(), t.end());
		cout << s + t << endl;
	}
	
	return 0;
}
