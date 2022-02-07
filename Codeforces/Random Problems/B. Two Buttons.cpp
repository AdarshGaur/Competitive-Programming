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
// int const mod = 998244353;
int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m;cin>>n>>m;
	queue<pii> q;
	q.push({n,0});
	vector<bool> vis(N, false);
	vis[n]=true;
	while(true){
		auto [u,v] = q.front();
		q.pop();
		if(u==m){
			cout<<v<<endl;
			exit(0);
		}
		int x = u-1, y = 2*u;
		if(x>0 and !vis[x]){
			q.push({x,v+1});
			vis[x]=true;
		}
		if(y<N and !vis[y]){
			q.push({y,v+1});
			vis[y]=true;
		}
	}
	return 0;
}
