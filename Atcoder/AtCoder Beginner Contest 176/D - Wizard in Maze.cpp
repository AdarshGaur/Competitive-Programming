// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
//int const mod = 998244353;
//int const N = 1e5 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int dx1[] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int dy1[] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int h, w, ci, cj, di, dj;
	cin>>h>>w>>ci>>cj>>di>>dj;
	ci--, cj--, di--, dj--;
	vector<string> maze(h);
	for(int i=0; i<h; i++){
		cin>>maze[i];
	}
	vector<vi> vis(h, vi(w, 0));
	typedef pair<pii, int> item; // { {x,y}, magic-used }
	deque<item> q;
	q.push_back({{ci, cj}, 0});
	vis[ci][cj] = 1;
	int ans=-1;
	while(!q.empty()){
		auto p = q.front();
		int u = p.ff.ff, v = p.ff.ss, m = p.ss;
		q.pop_front();
		vis[u][v] = 1;
		if(u==di and v==dj){
			ans = m;
			break;
		}
		for(int i=0; i<4; i++){
			int x = u+dx[i], y = v+dy[i];
			if(x<h and x>=0 and y>=0 and y<w and maze[x][y]=='.' and vis[x][y]==0)
				q.push_front({{x,y}, m});
		}
		for(int i=0; i<24; i++){
			int x = u + dx1[i], y = v+dy1[i];
			if(x>=0 and x<h and y>=0 and y<w and maze[x][y]=='.' and vis[x][y]==0)
				q.push_back({{x,y}, m+1});
		}
	}
	cout<<ans<<endl;
	return 0;
}
