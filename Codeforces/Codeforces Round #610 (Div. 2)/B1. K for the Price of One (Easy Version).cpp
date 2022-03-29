// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

void solve(){
	int n, p, k;
	cin >> n >> p >> k;
	int a[n+1];
	a[0] = -1;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	sort(a, a+n+1);
	int pref[n+1]={0}, sum[k]={0};
	for(int i = 1; i<=n; i++){
		if(i < k ){
			sum[i] = sum[i-1]+a[i];
		}else{
			pref[i] = a[i] + pref[i-k];
		}
	}
	int mx = 0;
	if(a[k] <= p) mx = k;
	else{
		for(int i=1; i<k; i++){
			if(sum[i] > p)break;
			mx = i;
		}
		cout << mx << endl;
		return;
	}
	for(int i=k+1; i<=n; i++){
		if(pref[i] > p)break;
		int t = p - pref[i];
		int lo = 1, hi = i % k, choose = 0;
		while(lo <= hi){
			int m = (lo + hi)>>1;
			if(sum[m] <= t){
				choose = m;
				lo = m + 1;
			}else{
				hi = m-1;
			}
		}
		mx = max(mx, i - (i%k) + choose);
	}
	cout << mx << endl;
}

int32_t main()
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
