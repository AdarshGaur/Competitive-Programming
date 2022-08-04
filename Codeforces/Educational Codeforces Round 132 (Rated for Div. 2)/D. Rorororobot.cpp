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

int const MAXN = 2e5 +7;
int const K = int(log2(MAXN)) +1;

int n;
int Log[MAXN+1];
int A[MAXN];
int ST[K][MAXN];
// ST[i][j] - index of maximum value from jth index till length 2^i


void ComputeLogs(){
	// store the log values
	Log[1]=0;
	for(int i=2; i<=MAXN; i++){
		Log[i] = Log[i/2]+1;
	}
}


void pre(){
	// Initialize the Sparse Table
	for(int i=0; i<n; i++){
		ST[0][i] = i;
	}

	// compute the other layers Sparse Table
	for(int j=1; j<K; j++){
		for(int i=0; i + (1<<j)-1 <n; i++){
			if( A[ ST[j-1][i] ] >  A[ ST[j-1][i + (1<<(j-1))] ]){
				ST[j][i] = ST[j-1][i];
			}else{
				ST[j][i] = ST[j-1][i+(1<<(j-1))];
			}
		}
	}
}

int query(int left ,int right){
	if(right < left)
		swap(left,right);
	int j = Log[right-left+1];
	return max(A[ ST[j][left] ], A[ ST[j][right-(1<<j) +1] ]);
}

void solve(){
	int m;
	cin >> m >> n;
	
	for(int i=0; i<n; i++)
		cin >> A[i];
	
	pre();
	
	int q;
	cin >> q;
	while(q--){
		int xs, ys, xf, yf, k;
		cin >> xs >> ys >> xf >> yf >> k;
		
		if(abs(yf-ys)%k != 0){
			cout << "NO" << endl;
			continue;
		}
		
		int gap = m - xs;
		int steps = gap /k;
		xs += steps*k;
		
		gap = m - xf;
		steps = gap/k;
		xf += steps*k;
		
		int mx = query(yf-1, ys-1);
		if(mx >= xs or mx >= xf or abs(xs-xf)%k != 0){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	ComputeLogs();
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
