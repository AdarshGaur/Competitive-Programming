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
int const N = 1007;

int mat[N][N];

void solve(){
	int n, q;
	cin >> n >> q;
	
	memset(mat, 0, sizeof(mat));
	for(int i=0; i<n; i++){
		int h, w;
		cin >> h >> w;
		mat[h][w] += h*w;
	}
	
	for(int i=1; i<N; i++){
		mat[i][0] += mat[i-1][0];
		mat[0][i] += mat[0][i-1];
	}
	
	for(int i=1; i<N; i++){
		for(int j=1; j<N; j++){
			mat[i][j] = mat[i][j] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
		}
	}
	
	while(q--){
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;
		cout << mat[hb-1][wb-1] + mat[hs][ws] - mat[hs][wb-1] - mat[hb-1][ws] << endl;
	}
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
