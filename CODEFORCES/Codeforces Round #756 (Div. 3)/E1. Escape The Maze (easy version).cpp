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
const int N = 1e6 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n, k;
	cin>>n>>k;
	deque<int> q;
	vi color(n, 0); // 0 -> unvisited; 2 -> friend will visit first; 1 -> vlad will visit first !!
	for(int i=0; i<k; i++){
		int x;cin>>x;
		q.push_back(--x);
		color[x]=2;
	}
	q.push_back(0);
	color[0]=1;
	vi adj[n]; /// my classical type of stupidity :/
	for(int i=0; i<n-1; i++){
		int u, v;cin>>u>>v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	while(!q.empty()){
		auto v = q.front();
		q.pop_front();
		for(auto u : adj[v]){
			if(color[u]==0){
				color[u] = color[v];
				q.push_back(u);
			}
		}
	}
	string ans="NO";
	for(int i=1; i<n; i++){
		if(color[i]==1 and adj[i].size()==1){
			ans="YES";
			break;
		}
	}
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        //string emptyy;
        //getline(cin, emptyy);
        solve();
    }

    return 0;
}

