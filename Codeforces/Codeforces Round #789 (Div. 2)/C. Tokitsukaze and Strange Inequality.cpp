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
	
	int p[n];
	for(int i=0; i<n; i++){
		cin >> p[i];
	}
	
	int bd[n]{};
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(p[i] > p[j])
				bd[i]++;	
		}
	}
	
	int ans = 0;
	for(int i = 1; i<n; i++){
		for(int j = 0; j<i; j++){
			if(p[j] > p[i])
				bd[j]--;
		}
		
		int pref[i]{};
		pref[0] = bd[0];
		for(int j=1; j<i; j++){
			pref[j] = pref[j-1] + bd[j];
		}
		
		for(int j=0; j<i; j++){
			if(p[j] < p[i]){
				ans += pref[i-1] - pref[j];
			}
		}
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
