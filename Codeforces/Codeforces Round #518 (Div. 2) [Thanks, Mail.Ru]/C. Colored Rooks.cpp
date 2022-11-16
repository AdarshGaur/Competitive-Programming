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

int const INF = 2e12;
int const mod = 1e9 +7;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n+7, vector<int>((n+7)*100, 0));
    for(int i=1; i<=n; i++){
        grid[i][i*100 +i] = 1;
        grid[i][0] = 1;
    }
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        grid[u][v*100 +u] = 1;
        grid[v][v*100 +u] = 1;
        grid[u][0]++, grid[v][0]++;
    }
    
    for(int i=1; i<=n; i++){
        cout << grid[i][0] << endl;
        for(int j=1; j < (n+7)*100; j++){
            if(grid[i][j] == 1){
                cout << i << " " << j << endl;
            }
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
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
