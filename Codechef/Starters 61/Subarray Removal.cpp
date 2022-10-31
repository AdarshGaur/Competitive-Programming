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
	
	vector<int> a(n);
	for(int &i: a)
		cin >> i;
	
	int ans = 0;
	vector<int> st;
	for(int i=0; i<n; i++){
		st.push_back(a[i]);
		while((int)st.size() >= 2 and st.back() != st[st.size()-2]){
			ans++;
			st.pop_back();
			st.pop_back();
		}
	}
	
	if((int)st.size() > 1 and st.back() == 1){
		int x = st.size();
		ans += x/3;
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
