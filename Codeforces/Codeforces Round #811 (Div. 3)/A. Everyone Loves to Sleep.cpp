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
	int n, H, M;
	cin >> n >> H >> M;
	
	int ansh, ansm;
	vector<pii> t(n);
	
	for(int i=0; i<n; i++){
		auto &[h, m] = t[i];
		cin >> h >> m;
		if(h < H){
			h += 24;
		}else if(h == H and m < M){
			h += 24;
		}
	}
	
	t.push_back({H,M});
	sort(t.begin(), t.end());
	
	for(int i=0; i<n; i++){
		auto [h,m] = t[i];
		auto [nh, nm] = t[i+1];
		if(h == H and m == M){
			ansh = nh - h;
			ansm = nm - m;
			if(nm < m){
				ansm += 60;
				ansh--;
			}
			break;
		}
	}
	
	cout << ansh << " " << ansm << endl;
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
