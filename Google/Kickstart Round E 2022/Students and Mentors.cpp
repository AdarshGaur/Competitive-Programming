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
	multiset<int> s;
	for(int &i: a){
		cin >> i;
		s.insert(i);
	}
	vector<int> ans(n);
	for(int i=0; i<n; i++){
		auto it1 = s.lower_bound(a[i]);
		s.erase(it1);
		if(s.empty()){
			ans[i] = -1;
			s.insert(a[i]);
			continue;
		}
		auto it = s.lower_bound(2*a[i]);
		if(it == s.begin()){
			if(*it <= 2*a[i]){
				ans[i] = *it;
			}else{
				ans[i] = -1;
			}
		}else{
			if(it == s.end() or *it > 2*a[i]){
				it--;
			}
			ans[i] = *it;
		}
		s.insert(a[i]);
	}
	for(int i=0; i<n; i++)
		cout << ans[i] << " \n"[i == n-1];
		 
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
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
