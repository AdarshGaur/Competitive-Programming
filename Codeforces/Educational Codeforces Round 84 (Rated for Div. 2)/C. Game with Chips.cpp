// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

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
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<k; i++){
		int x , y;
		cin >> x >> y >> x >> y;
	}
	string ans(n-1, 'U');
	ans += string (m-1, 'L');
	for(int i=0; i<n; i++){
		if(i != 0) ans += 'D';
		if(i&1){
			ans += string(m-1, 'L');
		}else{
			ans += string(m-1, 'R');
		}
	}
	cout << ans.size() << "\n" << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
