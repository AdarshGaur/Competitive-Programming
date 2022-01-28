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

int invertbit(int x){
	int y = log2(x) +1;
	for(int i=0; i<y; i++){
		x  = x ^ (1<<i);
	}
	return x;
}

void solve(){
	int n,k;cin>>n>>k;
	int sp1=n-1, sp2=k;
	bool vis[n]={false};
	if(k==n-1){
		sp2--;
	}
	vector<pii> ans;
	ans.push_back({sp1,sp2});
	vis[sp1] = vis[sp2] = true;
	if(k==n-1){
		if(vis[1] or vis[3]){
			cout<<-1<<endl;
			return;
		}
		ans.push_back({1,3});
		vis[1]=true;
		vis[3]=true;
	}
	for(int i=n-2; i >= n/2; i--){
		int f = invertbit(i);
		// int f = n - i;
		int p = i;
		if(vis[f] and vis[p])continue;
		if(vis[f]){
			f = 0;
		}else if(vis[p]){
			p=0;
		}
		ans.push_back({p,f});
		vis[p] = vis[f] = true;
	}
	for(auto[u,v] : ans){
		cout<<u<<" "<<v<<endl;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    while(test--)
        solve();
    return 0;
}
