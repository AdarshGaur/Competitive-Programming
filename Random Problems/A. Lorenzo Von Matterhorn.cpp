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


void solve(){
	int q;cin>>q;
	map<pii, int> mp;
	while(q--){
		int type, u, v;
		cin>>type>>u>>v;
		if(v<u)swap(u,v);
		if(type==1){
			int w;cin>>w;
			while(u<v){
				mp[{v,v/2}]+=w;
				v/=2;
			}
			while(u>v){
				mp[{u,u/2}]+=w;
				u/=2;
				if(u==v)break;
				mp[{v,v/2}]+=w;
				v/=2;
			}
		}else{
			int ans=0;
			while(u<v){
				if(mp[{v,v/2}]){
					ans += mp[{v,v/2}];
				}
				v/=2;
			}
			while(u>v){
				if(mp[{u,u/2}]){
					ans += mp[{u,u/2}];
				}
				u/=2;
				if(u==v)break;
				if(mp[{v,v/2}]){
					ans += mp[{v,v/2}];
				}
				v/=2;
			}
			cout<<ans<<endl;
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
