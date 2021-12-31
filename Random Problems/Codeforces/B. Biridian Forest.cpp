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

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

vector<string> ss;
int r, c, dis1, t;
bool vis[1002][1002];
int dis[1002][1002];

vi dx = {-1, 0, 1, 0};
vi dy = {0, -1, 0, 1};

void bfs(int a, int b){
	queue<pii> q;
	q.push({a,b});
	vis[a][b]=true;
	while(!q.empty()){
		auto v = q.front();
		int aa = v.ff, bb=v.ss;
		if(ss[aa][bb]=='E'){
			dis1=dis[aa][bb];
			break;
		}
		q.pop();
		for(int i=0; i<4; i++){
			int nx = aa + dx[i], ny=bb +dy[i];
			if(nx<r and nx>=0 and ny>=0 and ny<c and ss[nx][ny]!='T'){
				if(!vis[nx][ny]){
					q.push({nx, ny});
					vis[nx][ny]=true;
					dis[nx][ny]=dis[aa][bb]+1;
				}
			}
		}
	}
}

void bfs2(int a, int b){
	queue<pii> q;
	q.push({a,b});
	vis[a][b]=true;
	while(!q.empty()){
		auto v = q.front();
		int aa = v.ff, bb=v.ss;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = aa + dx[i], ny=bb +dy[i];
			if(nx<r and nx>=0 and ny>=0 and ny<c and ss[nx][ny]!='T'){
				if(!vis[nx][ny] and dis[aa][bb]!=dis1){
					vis[nx][ny]=true;
					q.push({nx, ny});
					dis[nx][ny]=dis[aa][bb]+1;
				}
			}
		}
	}
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    cin>>r>>c;
    for(int i=0; i<r; i++){
		string s;cin>>s;
		ss.push_back(s);
	}
	
	//find the distance1
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(ss[i][j]=='S'){
				bfs(i,j);
				break;
			}
		}
	}
	/////reset the visited matrix
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			vis[i][j]=false;
			dis[i][j]=0;
		}
	}
	
	////find the total no. of breeders;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(ss[i][j]=='E'){
				bfs2(i,j);
				break;
			}
		}
	}
	int cnt=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(vis[i][j] and ss[i][j]!='E' and ss[i][j]!='S'){
				cnt += (ss[i][j]-'0');
			}
		}
	}
	cout<<cnt<<endl;
    return 0;
}
