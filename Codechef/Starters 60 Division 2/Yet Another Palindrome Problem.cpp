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
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	int i = n/2 -1;
	int j = n/2 + (n %2);
	int cnt = 0, sum = 0;
	while(i >= 0){
		a[i] += sum;
		if(a[i] == a[j]){
			i--, j++;
		}else if(a[i] < a[j]){
			int x = a[j] - a[i];
			cnt += x;
			sum += x;
			i--, j++;
		}else{
			cout << -1 << endl;
			return;
		}
	}
	cout << cnt << endl;
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
