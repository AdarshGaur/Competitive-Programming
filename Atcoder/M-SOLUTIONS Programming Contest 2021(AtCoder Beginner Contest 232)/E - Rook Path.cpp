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
int const mod = 998244353;


void solve(){
	int H, W, K, x1, x2, y1, y2;
	cin >> H >> W >> K >> x1 >> y1 >> x2 >> y2;
	
	int a = 1, h = 0, w = 0, b = 0;
	for(int i=1; i<=K; i++){
		int ta = a, th = h, tw = w, tb = b;
		a = tw * (W-1) + th * (H-1);
		w = (H-1)*tb + ta + (W-2)*tw;
		h = (W-1)*tb + ta + (H-2)*th;
		b = th + tw + (H-2)*tb + (W-2)*tb;
		a %= mod;
		b %= mod;
		h %= mod;
		w %= mod;
	}
	int ans;
	if(x1 == x2 and y1 == y2){
		ans = a;
	}else if(x1 == x2){
		ans = w;
	}else if(y1 == y2){
		ans = h;
	}else{
		ans = b;
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
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
