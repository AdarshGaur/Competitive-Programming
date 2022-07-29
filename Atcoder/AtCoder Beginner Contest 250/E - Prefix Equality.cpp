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
	
	int a[n], b[n];
	for(int &i: a)
		cin >> i;
	for(int &i: b)
		cin >> i;
	
	
	int aSize[n], bSize[n];
	set<int> setA, setB;
	for(int i=0; i<n; i++){
		setA.insert(a[i]);
		setB.insert(b[i]);
		aSize[i] = setA.size();
		bSize[i] = setB.size();
	}
	setA.clear(), setB.clear();
	
	int sz = 0;
	map<int, int> mpa, mpb;
	bool possible[n+7];
	memset(possible, 0, sizeof(possible));
	
	for(int i=0, j=0; i<n and j<n;){
		
		while(i < n and mpa.count(a[i])) i++;
		while(j < n and mpb.count(b[j])) j++;
		if(i == n or j == n) break;

		mpa[a[i]]++;
		mpb[b[j]]++;
		sz++;
		
		if(setA.count(b[j])){
			setA.erase(b[j]);
		}else{
			setB.insert(b[j]);
		}
			
		if(setB.count(a[i])){
			setB.erase(a[i]);
		}else{
			setA.insert(a[i]);
		}

		if(setA.empty() and setB.empty())
			possible[sz] = true;
	}
	
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		x--, y--;
		
		if(aSize[x] != bSize[y]){
			cout << "No" << endl;
		}else{
			cout << (possible[aSize[x]] ? "Yes" : "No" ) << endl;
		}
		
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
