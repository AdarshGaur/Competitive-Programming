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
const int N = 2e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;
int n;
vi a, ans, odd, even;
vector<vi> adj;

void bfs(vi source, vi end){
	vi d(n, INF);
	deque<int> q;
	for(auto i: source){
		d[i] = 0;
		q.push_back(i);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(auto v : adj[u]){
			if(d[v]==INF){
				d[v] = d[u]+1;
				q.push_back(v);
			}
		}
	}
	for(auto i : end){
		if(d[i] != INF){
			ans[i] = d[i];
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // starting of program
	cin>>n;
	a = vi(n);
	ans = vi(n, -1);
	adj = vector<vi>(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i]&1)odd.push_back(i);
		else even.push_back(i);
		if(i-a[i]>=0){
			adj[i-a[i]].push_back(i);
		}
		if(i+a[i]<n){
			adj[i+a[i]].push_back(i);
		}
	}
	bfs(even, odd);
	bfs(odd, even);
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;
    return 0;
}
