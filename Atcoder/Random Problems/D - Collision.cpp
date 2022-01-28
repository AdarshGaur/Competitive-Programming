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


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	int n, q;cin>>n>>q;
	vi adj[n+1];
	for(int i=1; i<n; i++){
		int u, v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vi color(n+1,-1);
	queue<int> qq;
	qq.push(1);
	color[1]=1;
	while(!qq.empty()){
		int cur = qq.front();
		qq.pop();
		for(auto i: adj[cur]){
			if(color[i]==-1){
				color[i] = color[cur]+1;
				qq.push(i);
			}
		}
	}
	while(q--){
		int c, d;cin>>c>>d;
		if(color[c]%2 == color[d]%2){
			cout<<"Town"<<endl;
		}else{
			cout<<"Road"<<endl;
		}
	}
    return 0;
}
