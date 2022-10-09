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
	int n, k, r, c;
	cin >> n >> k >> r >> c;
	r--, c--;
	int si = r%k, sj = c%k;
	
	vector<vector<char>> mat(k, vector<char>(k, '.'));
	vector<vector<char>> out(n, vector<char>(n, '.'));
	
	
	for(int i=0; i<k; i++){
		mat[(si + i)%k][(sj +i)%k] = 'X';
	}
	
	
	for(int i=0; i<n/k; i++){
		for(int j=0; j<n/k; j++){
			for(int ii=0; ii<k; ii++){
				for(int jj=0; jj<k; jj++){
					out[i*k + ii][j*k + jj] = mat[ii][jj];
				}
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << out[i][j];
		}
		cout << endl;
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
