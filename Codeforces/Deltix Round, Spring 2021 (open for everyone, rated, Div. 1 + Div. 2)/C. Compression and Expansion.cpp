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
	
	vector<string> ans(1, "1");
	stack<int> st;
	st.push(1);
	for(int i=1; i<n; i++){
		if(a[i] == 1){ // new nested list
			ans.push_back(ans.back() + ".1");
			st.push(1);
		}else if(st.top() + 1 == a[i]){ // same list
			string x = ans.back();
			while(!x.empty() and x.back() != '.'){
				x.pop_back();
			}
			ans.push_back(x + to_string(a[i]));
			st.pop();
			st.push(a[i]);
		}else{ // end nested list
			string x = ans.back();
			while(st.top() + 1 != a[i]){
				st.pop();
				while(x.back() != '.') x.pop_back();
				x.pop_back();
			}
			while(!x.empty() and x.back() != '.'){
				x.pop_back();
			}
			ans.push_back(x + to_string(a[i]));
			st.pop();
			st.push(a[i]);
		}
	}
	
	for(auto &s: ans){
		cout << s << endl;
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
