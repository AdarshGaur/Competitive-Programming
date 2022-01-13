// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e16
const int mod = 1e9 +7;
//const int mod = 998244353;
const int N = 1e3 + 7;
int h,w,c,ans=INF;
int a[N][N], extra[N][N];

void solve(){
	int start[h][w], end[h][w];
	start[0][0] = a[0][0];
	for(int i=1; i<w; i++){
		start[0][i] = start[0][i-1]+c;
		end[0][i] = start[0][i] + a[0][i];
		start[0][i] = min(start[0][i], a[0][i]);
		ans = min(ans, end[0][i]);
	}
	for(int i=1; i<h; i++){
		start[i][0] = start[i-1][0]+c;
		end[i][0] = start[i][0] + a[i][0];
		start[i][0] = min(start[i][0], a[i][0]);
		ans = min(ans, end[i][0]);
	}
	for(int i=1; i<h; i++){
		for(int j=1; j<w; j++){
			start[i][j] = min(start[i][j-1],start[i-1][j])+c;
			end[i][j] = start[i][j] + a[i][j];
			start[i][j] = min(start[i][j], a[i][j]);
			ans = min(ans, end[i][j]);
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
    
    cin>>h>>w>>c;
    for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin>>a[i][j];
			extra[i][j] = a[i][j];
		}
	}
	solve();
	for(int i=0; i<w; i++){
		int t=0;
		for(int j=h-1; j>=0; j--){
			a[i][t++] = extra[j][i];
		}
	}
	solve();
	cout<<ans<<endl;
    return 0;
}
