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
	int n, pos{}, neg{};
	cin >> n;
	vector<int> a(n);
	for(int &i: a){
		cin >> i;
		if(i < 0) neg++;
		if(i > 0) pos++;
	}
	if(pos > 2 or neg > 2){
		cout << "NO" << endl;
		return;
	}
	sort(a.begin(), a.end());
	vector<int> b;
	for(int i=0; i<3; i++){
		b.push_back(a.back());
		a.pop_back();
	}
	for(int i=0; i<min<int>(a.size(), 2); i++)
		b.push_back(a[i]);
	
	map<int,bool> mp;
	n = b.size();
	
	for(int &i: b)
		mp[i] = true;
		
	string ans = "YES";
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k = j+1; k<n; k++){
				int s = b[i] + b[j] + b[k];
				if(!mp.count(s))
					ans = "NO";
			}
		}
	}
	
	cout << ans << endl;
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
