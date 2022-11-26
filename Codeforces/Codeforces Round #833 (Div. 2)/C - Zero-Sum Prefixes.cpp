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
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int ans = 0, j = 0, sum = 0;
	while(j < n and a[j] != 0){
		sum += a[j];
		ans += (sum == 0);
		j++;
	}
	
	if(j == n-1){
		cout << ans +1 << endl;
		return ;
	}
	
	for(int i=j+1; i<n; i++){
		int last = 0, mx = 1, cnt = 0;
		map<int,int> mp;
		while(i < n and a[i] != 0){
			last += a[i];
			cnt += last == 0;
			mp[last]++;
			mx = max(mx, mp[last]);
			i++;
		}
		ans += max(mx, cnt+1);
		if(i == n-1) ans++;
		mp.clear();
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
