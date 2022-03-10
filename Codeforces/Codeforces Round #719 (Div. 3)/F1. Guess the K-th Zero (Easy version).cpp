// Author : Adarsh Gaur 

// #define NDEBUG
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

int ask(int l, int r){
	cout << "? "<< l << " " << r << endl;
	cout.flush();
	int s;
	cin >> s;
	if( s == -1)exit(0);
	return s;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, t, k;
	cin >> n >> t >> k;
	int l = 1, r = n, ans = n;
	while(l <= r){
		int m = (l+r)>>1;
		int f = m-l+1 - ask(l, m);
		if( f < k){
			l = m+1;
			k -= f;
		}else{
			ans = m;
			r = m-1;
		}
	}
	cout << "! " << ans << endl;
	return 0;
}
