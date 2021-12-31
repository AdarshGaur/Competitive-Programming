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

bool vis[21][21];
int n,m;
string h, v;
int t=0;

void dfs(int a, int b){
	if(vis[a][b])return;
	vis[a][b]=true;
	t++;
	if(h[a]=='>' and b!=m-1){
		dfs(a, b+1);
	}else if(h[a]=='<' and b!=0){
		dfs(a, b-1);
	}
	if(v[b]=='^' and a!=0){
		dfs(a-1,b);
	}else if(v[b]=='v' and a!=n-1){
		dfs(a+1,b);
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

	cin>>n>>m>>h>>v;
	for(int k=0; k<n; k++){
		for(int k1=0; k1<m; k1++){
			dfs(k,k1);
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(!vis[i][j]){
						cout<<"NO"<<endl;
						return 0;
					}
					vis[i][j]=false;
				}
			}
		}
	}
	cout<<"YES"<<endl;
    return 0;
}
