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
	for(auto &i:a){
		cin>>i;
	}
	map<int,int> mp;
	for(auto &i:b){
		cin>>i;
		mp[i]++;
	}
	auto possible = [&](int x){
		auto freq = mp;
		for(int i=0; i<n; i++){
			freq[(a[i]+x)%m]--;
		}
		for(auto [u,v]: freq){
			if(v!=0){
				return false;
			}
		}
		return true;
	};
	int ans=INF;
	for(int i=0; i<n; i++){
		int change = b[i] -  a[0];
		if(b[i]<a[0])change+=m;
		if(possible(change)){
			ans = min(ans, change);
		}
	}
	cout<<ans<<endl;
	return 0;
}
