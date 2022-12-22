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
	string s;
	cin >> s;
	int n = s.size();
	int zeros = count(s.begin(), s.end(), '0');
	int ones = n - zeros;
	int ans = zeros;
	
	auto isPos = [&](int x){
		int l = 0, z = 0, o = 0;
		for(int i=0; i<n; i++){
			z += s[i] == '0';
			o += s[i] == '1';
			while(z > x){
				z -= s[l] == '0';
				o -= s[l] == '1';
				l++;
			}
			if(ones - o <= x)
				return true;
		}
		return false;
	};
	
	int lo = 0, hi = zeros;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if(isPos(mid)){
			ans = mid;
			hi = mid -1;
		}else{
			lo = mid +1;
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
