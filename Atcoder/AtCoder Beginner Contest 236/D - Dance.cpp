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

int n;
int a[20][20];
vector<pii> v;
bool used[20];

int best(){
	if((int)v.size() == n){
		int ans = 0;
		for(auto &[xa, xb]: v){
			ans ^= a[xa][xb];
		}
		return ans;
	}
	
	int first = 0;
	for(int i=0; i<2*n; i++){
		if(!used[i]){
			first = i;
			used[i] = true;
			break;
		}
	}
	
	int ans = 0;
	for(int i=0; i<2*n; i++){
		if(!used[i]){
			v.push_back({first, i});
			used[i] = true;
			ans = max(ans, best());
			used[i] = false;
			v.pop_back();
		}
	}
	used[first] = false;
	return ans;
}

void solve(){
	cin >> n;
	
	for(int i=0; i<2*n -1; i++){
		for(int j=i+1; j<2*n; j++){
			cin >> a[i][j];
		}
	}
	
	cout << best() << endl;
	
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
