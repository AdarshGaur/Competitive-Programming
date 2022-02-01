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


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int h, w, m;cin>>h>>w>>m;
	map<int,int> mpx, mpy;
	map<pii, int> mp;
	for(int i=0; i<m; i++){
		int x, y;cin>>x>>y;
		mpx[x]++;
		mpy[y]++;
		mp[{x,y}]=1;
	}
	vi a, b;
	int mxx=0, mxy=0;
	for(auto [u,v] : mpx){
		if(v>mxx){
			a.clear();
			mxx = v;
			a.push_back(u);
		}else if(v==mxx){
			a.push_back(u);
		}
	}
	for(auto [u,v] : mpy){
		if(v > mxy){
			b.clear();
			mxy = v;
			b.push_back(u);
		}else if(v==mxy){
			b.push_back(u);
		}
	}
	int ans = mxx + mxy;
	for(auto i: a){
		for(auto j: b){
			if(mp.count({i,j})==0){
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	cout<<ans-1<<endl;
	return 0;
}
