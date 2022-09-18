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

int n, m;
string a[10];
set<string> st;

void dfs(string s, vector<bool>& vis, int more, int taken){
	if(taken == n){
		if((int)s.size() >= 3 and (int)s.size() <= 16 and st.count(s) == 0){
			cout << s << endl;
			exit(0);
		}
		return;
	}
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		vis[i] = true;
		taken++;
		if(s.empty()){
			dfs(a[i], vis, more, taken);
		}else{
			for(int j = 0; j<= more; j++)
				dfs(s + string(1+j, '_') + a[i], vis, more-j, taken);
		}
		vis[i] = false;
		taken--;
	}
}

void solve(){
	cin >> n >> m;
	
	int len = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		len += a[i].size();
	}
	
	for(int i=0; i<m; i++){
		string x; cin >> x;
		st.insert(x);
	}
	
	if(n == 1 and (int)a[0].size() <= 2){
		cout << -1 << endl;
		return;
	}
	
	vector<bool> vis(n, false);
	
	int extra = 16 - (len + n -1);
	dfs("", vis, extra, 0);
	
	cout << -1 << endl;
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
