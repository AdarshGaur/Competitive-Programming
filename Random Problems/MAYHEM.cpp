/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
//#include <array>
//#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<pii> vpii;


#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forn(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define dbg(x) cout<<#x<<" = "<<x<<endl

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e10
#define endl "\n"

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////// Main functions start from here ////////



int n, m;
vector<vector<bool>> visited;
vvi mat;

int banks;


int x[] = {-1, 0, 1};
int y[] = {-1, 0, 1};


bool valid(int tx, int ty, int s){
	if(tx>=0 && tx<n && ty<m && ty>=0){
		if(!visited[tx][ty] && mat[tx][ty]==s){
			return true;
		}
	}
	return false;
}

void dfs(int a, int b, int s){
	banks++;
	visited[a][b]=true;
	int xc, yc;
	for(int i=0; i<3; ++i){
		xc = a + x[i];
		for(int j=0; j<3; ++j){
			yc = b + y[j];
			if(x[i] == y[j] || x[i]==-y[j]){
				continue;
			}
			if(valid(xc, yc, s)){
				dfs(xc, yc, s);
			}
		}
	}
}


signed main()
{
    fast_cin();
    cin>>n>>m;
    visited.resize(n, vector<bool> (m, false));
    mat.resize(n, vi (m));
    for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>mat[i][j];
		}
	}
	int strength = INF, tbanks=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(!visited[i][j]){
				banks=0;
				dfs(i,j,mat[i][j]);
				if(banks>tbanks){
					tbanks=banks;
					strength = mat[i][j];
				}else if(banks == tbanks && strength > mat[i][j]){
					strength = mat[i][j];
				}
			}
		}
	}
	cout << strength <<" "<<tbanks<<endl;
    return 0;
}
