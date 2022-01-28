// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int dxp[] = {-2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};
int dyp[] = {-1, 0, 1, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int h, w;
	cin>>h>>w;
	string s[h];
	for(int i=0; i<h; i++)
		cin>>s[i];
	vector<vi> dist(h, vi(w,INF));
	vector<vi> vis(h, vi(w, 0));
	dist[0][0]=0;
	deque<pii> q;
	q.push_back({0,0});
	while(!q.empty()){
		pii coord = q.front();
		q.pop_front();
		if(!vis[coord.ff][coord.ss]){
			vis[coord.ff][coord.ss]++;
			for(int i=0; i<4; i++){
				int x = coord.ff + dx[i];
				int y = coord.ss + dy[i];
				if(x>=0 && x<h && y>=0 && y<w){
					if(s[x][y]=='.'){
						dist[x][y] = min(dist[x][y], dist[coord.ff][coord.ss]);
						q.push_front({x,y});
					}
				}
			}
			for(int i=0; i<20; i++){
				int x = coord.ff + dxp[i];
				int y = coord.ss + dyp[i];
				if(x>=0 && x<h && y>=0 && y<w){
					dist[x][y] = min(dist[x][y], dist[coord.ff][coord.ss]+1);
					q.push_back({x,y});
				}
			}
		}
	}
	cout<<dist[h-1][w-1]<<endl;
    return 0;
}
