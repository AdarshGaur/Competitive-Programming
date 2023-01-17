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
	int n, m, total{};
	cin >> n >> m;
	
	
	int b[n];
	int a[n][m];
	for(int i=0; i<n; i++){
		int z = 0;
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			z += (a[i][j] == 1);
		}
		total += z;
		b[i] = z;
	}
	
	if(total %n != 0){
		cout << -1 << endl;
		return;
	}
	
	int need = total / n;
	
	vector<tuple<int,int,int>> ans;
	for(int j=0; j<m; j++){
		vector<int> extras;
		for(int i=0; i<n; i++){
			if(b[i] > need and a[i][j] == 1){
				extras.push_back(i);
			}
		}
		for(int i=0; i<n; i++){
			if(b[i] < need and a[i][j] == 0 and !extras.empty()){
				int l = extras.back();
				extras.pop_back();
				b[l]--;
				b[i]++;
				ans.push_back({i,l,j});
			}
		}
	}
	
	
	cout << (int)ans.size() << endl;
	if(!ans.empty()){
		for(auto &[i, j, k]: ans){
			cout << i+1 << " " << j+1 << " " << k+1 << endl;
		}
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
