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
	string t;
	cin >> t;
	
	int cost[n+1];
	memset(cost, -1, sizeof(cost));
	
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(t[i-1] == '0'){
			if(cost[i] == -1){
				cost[i] = i;
			}
			ans += cost[i];
			for(int j = i*2; j<=n; j += i){
				if(t[j-1] == '1') break;
				if(cost[j] == -1)
					cost[j] = i;
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
