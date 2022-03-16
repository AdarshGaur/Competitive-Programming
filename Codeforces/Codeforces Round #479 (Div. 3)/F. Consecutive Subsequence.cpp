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
	int n, mx=0, last = -1;
	cin >> n;
	int a[n];
	for(int &i: a){
		cin >> i;
	}
	map<int, int> mp;
	for(auto i : a){
		mp[i] = max(mp[i], mp[i-1]+1);
		if(mx < mp[i]){
			mx = mp[i];
			last = i;
		}
	}
	vi ans;
	for(int i=n-1; i>=0; i--){
		if( a[i] == last){
			ans.push_back(i);
			last--;
		}
	}
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	for(int i: ans){
		cout << i+1 << " ";
	}
	cout << endl;
	return 0;
}
