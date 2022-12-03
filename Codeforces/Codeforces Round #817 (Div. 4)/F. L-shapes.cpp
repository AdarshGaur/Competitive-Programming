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

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

bool sideTouch(int x, int y){
	for(int i : {-1, 0, 1}){
		for(int j: {-1, 0, 1}){
			if( i == 0 and j == 0) continue;
			int nx = x + i, ny = y + j;
			if(nx < 0 or nx == n or ny < 0 or ny == m) continue;
			if(grid[nx][ny] == '*' and vis[nx][ny]) return true;
		}
	}
	return false;
}

bool isLShape(int x, int y){
	// find what type of L shape is it
	if(x+1 < n and y-1 >= 0 and grid[x+1][y] == '*' and grid[x+1][y-1] == '*'){
		// . *
		// * *
		
		// perfrom proximity check
		if(!sideTouch(x, y) and !sideTouch(x+1, y-1) and !sideTouch(x+1, y))
			return true;
		
	}else if(x+1 < n and y+1 < m and grid[x+1][y] == '*' and grid[x][y+1] == '*'){
		// . * *
		// . * .
		if(!sideTouch(x,y) and !sideTouch(x+1, y) and !sideTouch(x, y+1))
			return true;
			
	}else if(x+1 < n and y+1 < m and grid[x+1][y+1] == '*' and grid[x][y+1] == '*'){
		// . * *
		// . . *
		if(!sideTouch(x,y) and !sideTouch(x+1,y+1) and !sideTouch(x, y+1))
			return true;
			
	}else if(x+1 < n and y+1 < m and grid[x+1][y] == '*' and grid[x+1][y+1] == '*'){
		// . * .
		// . * *
		if(!sideTouch(x,y) and !sideTouch(x+1, y) and !sideTouch(x+1, y+1))
			return true;
	}
	return false;
}


void dfs(int x, int y, int& cnt){
	if(x < 0 or y < 0 or x == n or y == m) return;
	if(vis[x][y]) return;
	vis[x][y] = true;
	if(grid[x][y] == '*'){
		cnt += 1;
		dfs(x+1, y, cnt);
		dfs(x-1, y, cnt);
		dfs(x, y+1, cnt);
		dfs(x, y-1, cnt);
	}
	return;
}


int hasThreeCells(int x, int y){
	int cnt = 0;
	dfs(x, y, cnt);
	return cnt == 3;
}

void solve(){
	cin >> n >> m;
	
	grid = vector<string>(n);
	for(int i=0; i<n; i++)
		cin >> grid[i];
	
	vis = vector<vector<bool>>(n, vector<bool>(m, false));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] == '*' and !vis[i][j]){
				if(!isLShape(i, j) or !hasThreeCells(i, j)){
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	
	cout << "YES" << endl;
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
