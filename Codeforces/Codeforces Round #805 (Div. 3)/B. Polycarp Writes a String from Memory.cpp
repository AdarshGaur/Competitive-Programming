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
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	string s;
	cin >> s;
	int days = 0;
	int n = s.size();
	for(int i=0; i<n;){
		set<char> st;
		days++;
		while(i<n and (int)st.size() < (int)4){
			if(st.count(s[i])){
				i++;
			}else{
				if(st.size() < 3){
					st.insert(s[i]);
					i++;
				}else{
					break;
				}
			}
		}
	}
	cout << days << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
