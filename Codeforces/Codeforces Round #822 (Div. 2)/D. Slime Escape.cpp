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
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i=0; i<k-1; i++){
		cin >> a[i];
	}
	
	int health;
	cin >> health;
	
	for(int i=k; i<n; i++){
		cin >> a[i];
	}
	
	vector<pii> leftSegs, rightSegs; // {sum, min}
	int sum = 0, mn = 0;
	for(int i = k-2; i>=0; i--){
		if(sum >= 0){
			leftSegs.push_back({sum,mn});
			sum = a[i];
			mn = min<int>(0, a[i]);
		}else{
			sum += a[i];
			mn = min(mn, sum);
		}
	}
	leftSegs.push_back({sum, mn});
	
	sum = 0, mn = 0;
	for(int i=k; i<n; i++){
		if(sum >= 0){
			rightSegs.push_back({sum, mn});
			sum = a[i];
			mn = min<int>(0, a[i]);
		}else{
			sum += a[i];
			mn = min(mn, sum);
		}
	}
	rightSegs.push_back({sum, mn});
	
	reverse(begin(rightSegs), end(rightSegs));
	reverse(begin(leftSegs), end(leftSegs));
	
	while(!rightSegs.empty() and !leftSegs.empty()){
		if(health + rightSegs.back().second >= 0){
			health += rightSegs.back().first;
			rightSegs.pop_back();
		}else if(health + leftSegs.back().second >= 0){
			health += leftSegs.back().first;
			leftSegs.pop_back();
		}else{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	
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
