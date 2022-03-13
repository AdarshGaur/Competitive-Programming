// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	map<pii, int> mp;
	int n; cin >> n;
	int x[n], y[n];
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	string s;
	cin >> s;
	for(int i=0; i<n; i++){
		if(s[i] == 'L'){
			if(mp.count({y[i], -1})){
				mp[{y[i], -1}] = max(mp[{y[i], -1}], x[i]);
			}else{
				mp[{y[i], -1}] = x[i];
			}
		}else{
			if(mp.count({y[i], 1})){
				mp[{y[i], 1}] = min(mp[{y[i], 1}], x[i]);
			}else{
				mp[{y[i], 1}] = x[i];
			}
		}
		if(mp.count({y[i],-1}) and mp.count({y[i],1})){
			if( mp[{y[i],-1}] > mp[{y[i],1}] ){
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
