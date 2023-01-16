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
	
	vector<pii> a(n+1);
	for(int i=0; i<=n; i++){
		a[i] = {i, 0};
	}
	
	for(int i=0; i<n-1; i++){
		int p; cin >> p;
		a[p].second += 1;
	}
	
	sort(a.begin(), a.end(), [&](pii &ap, pii& bp){
		if(ap.second == bp.second)
			return ap.first > bp.first;
		return ap.second > bp.second;
	});
	
	int curTime = 0;
	vector<int> v;
	for(int i=0; i<n; i++){
		if(a[i].second == 0) break;
		v.push_back(curTime + a[i].second);
		curTime += 1;
	}
	
	
	priority_queue<int> pq;
	for(int &i: v){
		if(i > curTime){
			pq.push(i - curTime);
		}
	}
	
	int extra = 1;
	while(!pq.empty() and pq.top() - extra > 0){
		extra++;
		int x = pq.top();
		pq.pop();
		pq.push(x-1);
	}
	
	cout << curTime + extra << endl;
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
