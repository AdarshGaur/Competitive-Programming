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
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> mat(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	
	int x = 0, y = 0;
	for(int i=0; i<n; i++){
		auto tmp = mat[i];
		sort(tmp.begin(), tmp.end());
		vector<int> swp;
		for(int j=0; j<m; j++){
			if(tmp[j] != mat[i][j]){
				swp.push_back(j);
			}
		}
		if(swp.empty()) continue;
		if(swp.size()  > 2){
			cout << -1 << endl;
			return;
		}
		x = swp[0], y = swp[1];
		break;
	}
	
	for(int i=0; i<n; i++){
		swap(mat[i][x], mat[i][y]);
		for(int j=1; j<m; j++){
			if(mat[i][j] < mat[i][j-1]){
				cout << -1 << endl;
				return;
			}
		}
	}
	
	cout << x+1 << " " << y+1 << endl;
	
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
