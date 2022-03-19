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

int dx[] = {0, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 0};
int dy[] = {-1, -1, 0, 0, 1, 1, 1, 1, 0, 0, -1, -1};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> mt(n);
	for(int i=0; i<n; i++){
		cin >> mt[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mt[i][j] == '0'){
				for(int k=0; k<12; k+=3){
					int x1 = i+dx[k], y1 = dy[k]+j;
					int x2 = i+dx[k+1], y2 = dy[k+1]+j;
					int x3 = i+dx[k+2], y3 = dy[k+2]+j;
					int xmx = max({x1, x2, x3}), ymx = max({y1, y2, y3});
					int xmn = min({x1, x2, x3}), ymn = min({y1, y2, y3});
					if(xmx <n and xmn >=0 and ymx < m and ymn >=0 ){
						if( mt[x1][y1] == '1' and
						mt[x2][y2] == '1' and
						mt[x3][y3] == '1'){
							cout << "NO" << endl;
							return;
						}
					}
				}
			}
		}
	}
	cout << "YES" << endl;
}

int32_t main()
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
