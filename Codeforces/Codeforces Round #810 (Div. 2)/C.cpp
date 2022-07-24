// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[k];
	for(int &i: a)
		cin >> i;
	sort(a, a+k);
	auto check = [&](int rn, int rm){
		for(int i=0; i<k; i++){
			int t = min(rn, a[i]/rm);
			if(t < rn)
				t = min(t, rn -2);
			if(t != 1) rn -= t;
		}
		return rn == 0;
	};
	if(check(n, m) or check(m, n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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
