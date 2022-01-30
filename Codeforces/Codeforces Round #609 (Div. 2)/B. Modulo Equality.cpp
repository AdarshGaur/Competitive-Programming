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
	int n, m;cin>>n>>m;
	int a[n], b[n];
	unordered_map<int,int> ta, tb;
	for(auto &i:a){
		cin>>i;
		ta[i]++;
	}
	for(auto &i:b){
		cin>>i;
		tb[i]++;
	}
	unordered_map<int,int> mp;
	int cnt=0;
	for(auto [aa, freqaa]: ta){
		vi pos;
		cnt++;
		for(auto [x,y] : tb){
			if(freqaa == y){
				if(x < aa){
					pos.push_back(x+m-aa);
				}else{
					pos.push_back(x-aa);
				}
			}
		}
		sort(pos.begin(), pos.end());
		auto ik = unique(pos.begin(), pos.end());
		for(auto it = pos.begin(); it!=ik; it++){
			mp[*it]++;
		}
	}
	int ans=INF;
	for(auto [u,v]: mp){
		if(v==cnt){
			ans = min(ans, u);
		}
	}
	cout<<ans<<endl;
	return 0;
}
