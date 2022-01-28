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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

map<pii, int> mp;

int LCA(int a, int b){
	if(a==b)return a;
	if(b<a)swap(a,b);
	return LCA(a, b/2);
}

void update_path(int a, int b, int w){
	while(a!=b){
		mp[{a,a/2}]+=w;
		a/=2;
	}
}

int find_val(int a, int lca){
	int ans=0;
	while(a!=lca){
		ans += mp[{a,a/2}];
		a/=2;
	}
	return ans;
}

void solve(){
	int q;cin>>q;
	while(q--){
		int type, u, v;
		cin>>type>>u>>v;
		int lca = LCA(u, v);
		if(type==1){
			int w;cin>>w;
			update_path(u, lca, w);
			update_path(v, lca, w);
		}else{
			cout<<find_val(u,lca)+find_val(v,lca)<<endl;
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
